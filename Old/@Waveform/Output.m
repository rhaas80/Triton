% Output(Wi, FileBaseName)
% Output(Wi, FileBaseName, Format)
% Output(Wi, FileBaseName, Format, TimeAxis)
% 
%   This function outputs the Waveform object to a set of
%   files.  The file names are determined by FileBaseName, to
%   which the Type is prepended, and LM or ThetaPhi data and a
%   '.dat' extension are appended.  If FileBaseName contains
%   'Identifier', the objects Identifier string is
%   substituted.  All colons are converted to '-', because of
%   the Mac file system, which does not always handle colons
%   well.  The Format may be one of
%     'ReIm', 'AmpPhi', 'PhiAmp', 'NegPhiAmp'
%   corresponding to the formats in the Waveform.m
%   constructor.  The default is 'ReIm'.  The final argument
%   TimeAxis is the label for the time axis, placed in the
%   header of the .dat file.  The default is simply 'Time'.
%   The PostProcessing information is placed in a file with
%   the Type and FileBaseName as above, with an extension of
%   '.metadata'.

function Output(varargin)
    %%% Get input arguments
    Time = clock;
    Date = date;
    Format = 'ReIm';
    TimeAxis = 'Time';
    W = varargin{1};
    Tokens = regexp(varargin{2}, '(.*\/)(.*)', 'tokens');
    if(length(Tokens)==0);
        Directory = './';
        FileBaseName = varargin{2};
    else;
        Tokens = Tokens{1,1};
        Directory = char(Tokens{1});
        FileBaseName = char(Tokens{2});
    end;
    FileBaseName = regexprep(FileBaseName, 'Identifier', ...
                             W.Identifier);
    FileBaseName = regexprep(FileBaseName, ':', '-');
    if(nargin>=3);
        Format = varargin{3};
    end;
    if(nargin==4);
        TimeAxis = varargin{4};
    end;
    
    %%% Note the output in PostProcessing
    DataSec = '[files]';
    if(strcmp(lower(Format), 'reim'));
        FormatTag = '';
    else;
        FormatTag = [lower(Format) '-'];
    end;
    if(strcmp(lower(W.Type), 'f{rmpsi4}'));  DataSec = ['[psi4f-' FormatTag 'data]']; end;
    if(strcmp(lower(W.Type), 'f{psi4}'));    DataSec = ['[psi4f-' FormatTag 'data]']; end;
    if(strcmp(lower(W.Type), 'f{rhoverm}')); DataSec = ['[hf-' FormatTag 'data]']; end;
    if(strcmp(lower(W.Type), 'f{h}'));       DataSec = ['[hf-' FormatTag 'data]']; end;
    if(strcmp(lower(W.Type), 'rmpsi4'));  DataSec = ['[psi4t-' FormatTag 'data]']; end;
    if(strcmp(lower(W.Type), 'psi4'));    DataSec = ['[psi4t-' FormatTag 'data]']; end;
    if(strcmp(lower(W.Type), 'rhoverm')); DataSec = ['[ht-' FormatTag 'data]']; end;
    if(strcmp(lower(W.Type), 'h'));       DataSec = ['[ht-' FormatTag 'data]']; end;
    W.PostProcessing = ...
        [W.PostProcessing; ...
         {''}; {'[output]'}; ...
         {sprintf('OutputDate = ''%s %.2d:%.2d:%f'';', ...
                  Date, Time(4:6))}; ...
         {sprintf('OutputPwd = ''%s'';', pwd)}; ...
         {sprintf('Output(this, ''%s%s'', ''%s'', ''%s'');', ...
                  Directory, FileBaseName, Format, TimeAxis)}; ...
         {''}; ...
         {DataSec} ...
        ];
    
    %%% Loop through LM data, outputting a separate file for each
    for k = 1:size(W.LM,1);
        lm = W.LM(k,:);
        FileName = sprintf('%s_%s_L%d_M%d.dat', ...
                           W.Type, FileBaseName, lm(1), lm(2));
        W.PostProcessing = [W.PostProcessing; ...
                            {[sprintf('%d,%d \t= ', lm(1), lm(2)) FileName]}];
        File = fopen([Directory FileName], 'w');
        switch lower(Format)
          case 'reim'
            fprintf(File, '# [1] = %s\n', TimeAxis);
            fprintf(File, '# [2] = Re{%s(l=%d, m=%d)}\n', ...
                    W.Type, lm(1), lm(2));
            fprintf(File, '# [3] = Im{%s(l=%d, m=%d)}\n', ...
                    W.Type, lm(1), lm(2));
            C = W.Amp(:,k) .* (cos(W.Phi(:,k)) + i*sin(W.Phi(:,k)));
            fprintf(File, '%.16g %.16g %.16g\n', ...
                    [W.Time, real(C), imag(C)]');
          case 'ampphi'
            fprintf(File, '# [1] = %s\n', TimeAxis);
            fprintf(File, '# [2] = Abs{%s(l=%d, m=%d)}\n', ...
                    W.Type, lm(1), lm(2));
            fprintf(File, '# [3] = Arg{%s(l=%d, m=%d)}\n', ...
                    W.Type, lm(1), lm(2));
            fprintf(File, '%.16g %.16g %.16g\n', ...
                    [W.Time, W.Amp(:,k), W.Phi(:,k)]');
          case 'phiamp'
            fprintf(File, '# [1] = %s\n', TimeAxis);
            fprintf(File, '# [2] = Arg{%s(l=%d, m=%d)}\n', ...
                    W.Type, lm(1), lm(2));
            fprintf(File, '# [3] = Abs{%s(l=%d, m=%d)}\n', ...
                    W.Type, lm(1), lm(2));
            fprintf(File, '%.16g %.16g %.16g\n', ...
                    [W.Time, W.Phi(:,k), W.Amp(:,k)]');
          case 'negphiamp'
            fprintf(File, '# [1] = %s\n', TimeAxis);
            fprintf(File, '# [2] = -Arg{%s(l=%d, m=%d)}\n', ...
                    W.Type, lm(1), lm(2));
            fprintf(File, '# [3] =  Abs{%s(l=%d, m=%d)}\n', ...
                    W.Type, lm(1), lm(2));
            fprintf(File, '%.16g %.16g %.16g\n', ...
                    [W.Time, -W.Phi(:,k), W.Amp(:,k)]');
        end; % switch
        fclose(File);
    end; % LM loop
    
    %%% Loop through ThetaPhi, outputting a separate file for each
    %if(length(W.ThetaPhi
    for k = 1:size(W.ThetaPhi,1);
        tp = W.ThetaPhi(k,:);
        FileName = sprintf('%s%s_%s_Theta%.16g_Phi%.16g.dat', ...
                           Directory, W.Type, FileBaseName, ...
                           tp(1), tp(2));
        W.PostProcessing = [W.PostProcessing; ...
                            {['''' FileName ''';']}];
        File = fopen(FileName, 'w');
        switch lower(Format)
          case 'reim'
            fprintf(File, '# [1] = %s\n', TimeAxis);
            fprintf(File, ['# [2] = Re{%s(theta=%.16g, ' ...
                           'phi=%.16g)}\n'], ...
                    W.Type, tp(1), tp(2));
            fprintf(File, ['# [3] = Im{%s(theta=%.16g, ' ...
                           'phi=%.16g)}\n'], ...
                    W.Type, tp(1), tp(2));
            C = W.Amp(:,k) .* (cos(W.Phi(:,k)) + i*sin(W.Phi(:,k)));
            fprintf(File, '%.16g %.16g %.16g\n', ...
                    [W.Time, real(C), imag(C)]');
          case 'ampphi'
            fprintf(File, '# [1] = %s\n', TimeAxis);
            fprintf(File, ['# [2] = Abs{%s(theta=%.16g, ' ...
                           'phi=%.16g)}\n'], ...
                    W.Type, tp(1), tp(2));
            fprintf(File, ['# [3] = Arg{%s(theta=%.16g, ' ...
                           'phi=%.16g)}\n'], ...
                    W.Type, tp(1), tp(2));
            fprintf(File, '%.16g %.16g %.16g\n', ...
                    [W.Time, W.Amp(:,k), W.Phi(:,k)]');
          case 'phiamp'
            fprintf(File, '# [1] = %s\n', TimeAxis);
            fprintf(File, ['# [2] = Arg{%s(theta=%.16g, ' ...
                           'phi=%.16g)}\n'], ...
                    W.Type, tp(1), tp(2));
            fprintf(File, ['# [3] = Abs{%s(theta=%.16g, ' ...
                           'phi=%.16g)}\n'], ...
                    W.Type, tp(1), tp(2));
            fprintf(File, '%.16g %.16g %.16g\n', ...
                    [W.Time, W.Phi(:,k), W.Amp(:,k)]');
          case 'negphiamp'
            fprintf(File, '# [1] = %s\n', TimeAxis);
            fprintf(File, ['# [2] = -Arg{%s(theta=%.16g, ' ...
                           'phi=%.16g)}\n'], ...
                    W.Type, tp(1), tp(2));
            fprintf(File, ['# [3] =  Abs{%s(theta=%.16g, ' ...
                           'phi=%.16g)}\n'], ...
                    W.Type, tp(1), tp(2));
            fprintf(File, '%.16g %.16g %.16g\n', ...
                    [W.Time, -W.Phi(:,k), W.Amp(:,k)]');
        end; % switch
        fclose(File);
    end; % ThetaPhi loop
    
    %%% Output PostProcessing data
    File = fopen([Directory W.Type '_' FileBaseName '.metadata'], ...
                 'w');
    for k = 1:length(W.PostProcessing)
        fprintf(File, '%s\n', char(W.PostProcessing{k}));
    end
    fclose(File);
    
end
