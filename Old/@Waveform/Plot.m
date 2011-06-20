% Plot(W1, W2, ...)
% Plot(W1, W2, ..., 'after', Time1, ...)
% Plot(W1, W2, ..., 'before', Time2, ...)
% Plot('Amp', W1, W2, ...)
% Plot('Phi', W1, W2, ...)
% 
%   This is the function for plotting Waveform objects.  Any
%   number may be plotted.  The default behavior is to plot
%   the real and imaginary parts.  If 'Amp' or 'Phi' is the
%   first argument, the amplitude or phase will be plotted
%   instead.  The xlimits may also be set with optional
%   arguments, which can come anywhere in the argument list.

function Plot(varargin)

Argin = varargin;
Quantity = 'ReIm';
FrequencyDomain = false;
xMin = -10^200;
xMax =  10^200;
Legend = cell(0,1);

%%% Loop through the input arguments
for k=1:nargin
    if(isa(Argin{k}, 'Waveform'));
        %hold(a);
        for j=1:size(Argin{k}.LM,1);
            Legend{end+1} = sprintf('(%d,%d)', Argin{k}.LM(j,1), Argin{k}.LM(j,2));
        end;
        switch lower(Quantity)
          case 'reim'
            hold all;
            plot(Argin{k}.Time, Re(Argin{k}),...
                 Argin{k}.Time, Im(Argin{k}));
          case 'amp'
            if(~isempty(regexpi(Argin{k}.Type, 'F{')));
                loglog(Argin{k}.Time, Argin{k}.Amp);
                FrequencyDomain = true;
                hold all;
            else;
                hold all;
                plot(Argin{k}.Time, Argin{k}.Amp);
            end;
          case 'phi'
            if(~isempty(regexpi(Argin{k}.Type, 'F{')));
                plot(Argin{k}.Time, Argin{k}.Phi);
                hold all;
                FrequencyDomain = true;
            else;
                hold all;
                plot(Argin{k}.Time, Argin{k}.Phi);
            end;
        end;
    elseif(isa(Argin{k}, 'char'));
        switch lower(Argin{k})
          case 'after'
            xMin = Argin{k+1};
            Argin{k+1} = 0;
          case 'before'
            xMax = Argin{k+1};
            Argin{k+1} = 0;
          case 'amp'
            Quantity = 'Amp';
          case 'phi'
            Quantity = 'Phi';
          otherwise
        end;
    else;
        % Ignore the argument
    end;
end % for k=1:nargin


%%% Make it pretty
a = gca; %% Get current axes;
X = get(a, 'XLim');
XMin = X(1);
XMax = X(2);
if(xMin > XMin);
    XMin = xMin;
end;
if(xMax < XMax);
    XMax = xMax;
end;
xlim([XMin XMax]);
ylim('auto');
if(FrequencyDomain);
    XLabel = 'Frequency';
    YLabelA = 'Amplitude of F\{h\} or F\{\Psi_4\}';
    YLabelP = 'Phase (arg) of F\{h\} or F\{\Psi_4\}';
    YLabelR = 'Real and Imaginary parts of F\{h\} or F\{\Psi_4\}';
else;
    XLabel = 'Time';
    YLabelA = 'Amplitude of h or \Psi_4';
    YLabelP = 'Phase (arg) of h or \Psi_4';
    YLabelR = 'Real and Imaginary parts of h or \Psi_4';
end;
xlabel(XLabel);
switch lower(Quantity)
  case 'reim'
    ylabel(YLabelR);
  case 'amp'
    ylabel(YLabelA);
  case 'phi'
    ylabel(YLabelP);
end;
title('GW Waveforms');
legend(Legend);