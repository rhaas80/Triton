def ReadWaveform(File) :
    """
    Read a single h5 waveform file in NRAR format.
    """
    import h5py
    import PyGW_IS_FOR_OLD_DATA
    import re
    import numpy
    YlmRegex = re.compile(r""".*_l(?P<L>[0-9]+)_m(?P<M>[-+0-9]+).*\.dat""")
    f = h5py.File(File, 'r')
    datasetlist = list(f)
    W = PyGW_IS_FOR_OLD_DATA.Waveform()
    NTimes = f[datasetlist[0]].shape[0]
    YLMdata = [DataSet for DataSet in datasetlist for m in [YlmRegex.search(DataSet)] if m]
    YLMdata = sorted(YLMdata, key=lambda DataSet : [int(YlmRegex.search(DataSet).group('L')), int(YlmRegex.search(DataSet).group('M'))])
    NModes = len(YLMdata)
    W.AppendHistory("### # Python read from {0}.".format(File))
    W.SetT(f[datasetlist[0]][:,0])
    W.SetLM(PyGW_IS_FOR_OLD_DATA.MatrixInt(sorted([[int(m.group('L')), int(m.group('M'))] for DataSet in YLMdata for m in [YlmRegex.search(DataSet)] if m])))
    W.SetMag(PyGW_IS_FOR_OLD_DATA.MatrixDouble(numpy.array([f[dataset][:,1] for dataset in datasetlist])))
    W.SetArg(PyGW_IS_FOR_OLD_DATA.MatrixDouble(numpy.array([f[dataset][:,2] for dataset in datasetlist])))
    W.ConvertReImToMagArg()
    for i,type in enumerate(W.Types) :
        if(File.find(type)>-1) :
            W.SetTypeIndex(i)
            break
    f.close()
    return W

def WriteWaveform(FileName, W) :
    """
    Write a single h5 waveform file in NRAR format.
    
    If the FileName contains a colon, the part before the colon is
    taken to be the path, and the part following is taken to be the
    HDF5 group into which the waveform is to be written.  This allows
    a SpEC-style h5 file to be built up with multiple calls to this
    function.
    
    The return value is a string which should be appended to the
    appropriate '.bbh' file.
    """
    import h5py
    import PyGW_IS_FOR_OLD_DATA
    import re
    import numpy
    BBHString = ''
    FileRegex = re.compile(r"""(?P<File>[^:]*):?(?P<Group>.*)""")
    FileMatch = FileRegex.search(FileName)
    File = FileMatch.group('File')
    Group = FileMatch.group('Group')
    if not File :
        raise(ValueError('No file name found in "{0}".  Make sure there is content before any colon.'.format(FileName)))
    f = h5py.File(File, 'w')
    if Group :
        if Group[-1] == '/' :
            Group = Group[:-1]
        grp = f.create_group(Group)
        FileAndGroup = "{File}:{Group}/".format(File=File,Group=Group)
    else :
        grp = f
        FileAndGroup = "{File}:".format(File=File)
    Type = (W.Types[( W.TypeIndex() % 3 ) + 9]).lower()
    BBHString += "\n[{0}t-data]\n".format(Type)
    for i,LM in enumerate(W.LM()) :
        L=LM[0]
        M=LM[1]
        DataSetName = 'Y_l{L}_m{M}.dat'.format(L=L,M=M)
        BBHString += "{L},{M} = {FileAndGroup}{DataSetName}\n".format(L=L,M=M,FileAndGroup=FileAndGroup,DataSetName=DataSetName)
        dat = grp.create_dataset(DataSetName, (W.NTimes(),3), dtype='f')
        dat[:,0] = W.T()
        Mag = W.Mag(i)
        Arg = W.Arg(i)
        dat[:,1] = Mag*numpy.cos(Arg)
        dat[:,2] = Mag*numpy.sin(Arg)
    f.close()
    return BBHString
