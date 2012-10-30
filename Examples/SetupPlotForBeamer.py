# Define some colors that my beamer class uses
CornellRed = '#B31B1B'
CornellLightRed = '#D94F4F'
CornellDarkRed = '#740909'
CornellGray = '#68645B'
CornellLighterGray = '#D9D4CA'
CornellLightGray = '#B3AEA3'
CornellDarkGray = '#4E4C47'
CornellDarkerGray = '#262527'
CornellDarkestGray = '#1D1C1D'
CornellGreen = '#168F16'
CornellBlue = '#184B73'

# For output to pdf when saving (these settings are otherwise 'interactive' agnostic)
matplotlib.rcParams['savefig.extension'] = 'pdf'

# This makes lines thicker than the default, and changes the default
#   font size to the same as the paper's font size.  To get the
#   current font parameters in a LaTeX document, put something like
#   
# \makeatletter %
# \newcommand{\ShowFont}{\typeout{The font is \f@encoding \space
#     \f@family \space \f@series \space \f@shape \space at
#     \f@size pt}} %
# \makeatother %
#   
#   in the preamble, then "\ShowFont" wherever you want to see it,
#   and grep the output for "The font is".  Note that if you have
#   more than one in a single document, the output may be out of
#   order.  For math font sizes, ask for \tf@size (main),
#   \sf@size (script), and \ssf@size (scripscript).  See the LaTeX2e
#   font selection guide for more details.
# In beamer, the default font is cmss and the math font size 10.95pt.
matplotlib.rcParams['lines.linewidth'] = 1.5
matplotlib.rcParams['font.size'] = 10.95 # pt

matplotlib.rcParams['text.usetex'] = True
matplotlib.rcParams['text.latex.preamble'] = [r'\usepackage{amsmath}', r'\usepackage{bm}', r'\usepackage{graphicx}']
import os
if os.path.isfile("UsePackages.tex") :
    matplotlib.rcParams['text.latex.preamble'].append(r'\input{' + os.getcwd() + r'/UsePackages}')
if os.path.isfile("Macros.tex") :
    matplotlib.rcParams['text.latex.preamble'].append(r'\input{' + os.getcwd() + r'/Macros}')
matplotlib.rcParams['text.latex.preamble'].append(r'\usepackage{tgheros}')
matplotlib.rcParams['text.latex.preamble'].append(r'\renewcommand*\familydefault{\sfdefault}')
matplotlib.rcParams['text.latex.preamble'].append(r'\usepackage{sfmath}')
matplotlib.rcParams['text.latex.preamble'].append(r'\usepackage[T1]{fontenc}')

matplotlib.rcParams['axes.linewidth'] = 1.5     # edge linewidth

# To get the linewidth of a LaTeX document, put something like
#   "\typeout{The linewidth is \the\linewidth}", and grep the output
#   for "linewidth".  In my Cornell beamer class, the text area is
#   334.195pt across, and 220.647pt high.
# Note that 1pt = (1/72)inches = (1/12)pica
FigureHeight = 220.64662/72.0 # in inches
FigureWidth = 247.69934/72.0 # in inches
#FigureWidth = 334.19536/72.0 # in inches
matplotlib.rcParams['figure.figsize'] = [FigureWidth, FigureHeight]  # figure size in inches
matplotlib.rcParams['figure.dpi'] = 200  # figure dots per inch

rc('font', family='sans-serif', weight='normal', style='normal')

## This redraws each figure with the appropriate size
FigureList=[manager.canvas.figure
         for manager in matplotlib._pylab_helpers.Gcf.get_all_fig_managers()]
## Set size and re-draw with all defaults
for temp, ThisFig in enumerate(FigureList) :
    ThisFig.set_figheight(FigureHeight)
    ThisFig.set_figwidth(FigureWidth)
    for line in ThisFig.gca().get_xticklines() + ThisFig.gca().get_yticklines():
        line.set_markeredgewidth(1.25)
        #tick.label1.set_family('sans-serif')
    ThisFig.canvas.draw()
## Tighten in separate loop; maybe draw will have finished
for temp, ThisFig in enumerate(FigureList) :
    ThisFig.tight_layout(pad=0.1)
