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
# Note also that captions in revtex4 are typeset with \small; when
#   most of the document is 10pt, \small is 9pt.
# In beamer, the default font is cmss and the math font size 10.95pt.
matplotlib.rcParams['lines.linewidth'] = 1.5
matplotlib.rcParams['font.size'] = 9.0 # pt

matplotlib.rcParams['text.usetex'] = True
matplotlib.rcParams['text.latex.preamble'] = [r'\usepackage{amsmath}', r'\usepackage{bm}', r'\usepackage{graphicx}']
import os
if os.path.isfile("UsePackages.tex") :
    matplotlib.rcParams['text.latex.preamble'].append(r'\input{' + os.getcwd() + r'/UsePackages}')
if os.path.isfile("Macros.tex") :
    matplotlib.rcParams['text.latex.preamble'].append(r'\input{' + os.getcwd() + r'/Macros}')

matplotlib.rcParams['axes.linewidth'] = 1.5     # edge linewidth

# To get the linewidth of a LaTeX document, put something like
#   "\typeout{The linewidth is \the\linewidth}", and grep the output
#   for "linewidth".  In revtex4, we have the following widths:
#            onecolumn   twocolumn
#     10pt     510pt       246pt
#     12pt     468pt       229pt
# PRD editors seem to like resizing things to fit in a 200x200pt box
#   by default, and move axis labels out from the axes, but I like to
#   keep figures the full width.
# Note that 1pt = (1/72)inches = (1/12)pica
FigureHeight = 246/72.0 # in inches
FigureWidth = 229/72.0 # in inches
matplotlib.rcParams['figure.figsize'] = [FigureWidth, FigureHeight]    # figure size in inches


## This redraws each figure with the appropriate size
FigureList=[manager.canvas.figure
         for manager in matplotlib._pylab_helpers.Gcf.get_all_fig_managers()]
## Set size and re-draw with all defaults
for temp, ThisFig in enumerate(FigureList) :
    ThisFig.set_figheight(FigureHeight)
    ThisFig.set_figwidth(FigureWidth)
    for line in ThisFig.gca().get_xticklines() + ThisFig.gca().get_yticklines():
        line.set_markeredgewidth(2)
    ThisFig.canvas.draw()
## Tighten in separate loop; maybe draw will have finished
for temp, ThisFig in enumerate(FigureList) :
    ThisFig.tight_layout(pad=0.1)
