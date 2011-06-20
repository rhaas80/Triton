% W(Indices)
% 
%   This function returns a Waveform containing a subset of
%   the data consisting of columns of Amp and Phi given by
%   the vector (or single number) Indices.
% 
% 
% W.[field]
% 
%   This function returns the data held by the Waveform
%   object W in the requested field.  For example 'W.Amp'
%   would return a matrix containing the amplitude data.  The
%   names of all the fields can be found with 'fieldnames(W)',
%   where W is some Waveform object.

function varargout = subsref(W,Indices)

k = Indices(1, 1);

switch k.type
    
  case '()'  % Returns a W with only the requested columns of
             % Amp and Phi
    if(max(k.subs{:})<=size(W.Amp,2))
        Ind = k.subs{:};
        Return = W;
        if(size(Ind,2)==2);
            LMList = [];
            for i = 1:size(Ind,1);
                LMList = [LMList find(W.LM(:,1)==Ind(i,1) & W.LM(:,2)==Ind(i,2))];
            end;
            Ind = LMList';
        end;
        try;
            Return.LM = W.LM(Ind,:);
        catch;
            try;
                Return.ThetaPhi = W.ThetaPhi(Ind,:);
            catch;
            end;
        end;
        Return.PhaseOffset = W.PhaseOffset(Ind);
        Return.Amp = W.Amp(:, Ind);
        Return.Phi = W.Phi(:, Ind);
        if(numel(Ind)==1);
            Return.PostProcessing = ...
                [Return.PostProcessing; ...
                 {sprintf('this = this(%.16g);', Ind)}];
        else;
            Return.PostProcessing = ...
                [Return.PostProcessing; ...
                 {['this = this([' ...
                   sprintf('%.16g, ', Ind(1:(end-1))) ...
                   sprintf('%.16g]);', Ind(end))]}];
        end;
        varargout{1} = Return;
    else
        error('Waveform subsref: Index out of bounds');
    end
    
  case '.'  % Data access methods
    switch k.subs
      case 'Type'
        varargout{1} = W.Type;
      case 'Identifier'
        varargout{1} = W.Identifier;
      case 'LM'
        varargout{1} = W.LM;
      case 'ThetaPhi'
        varargout{1} = W.ThetaPhi;
      case 'PostProcessing'
        varargout{1} = W.PostProcessing;
      case 'TimeOffset'
        varargout{1} = W.TimeOffset;
      case 'PhaseOffset'
        varargout{1} = W.PhaseOffset;
      case 'Time'
        varargout{1} = W.Time;
      case 'Radius'
        varargout{1} = W.Radius;
      case 'Amp'
        varargout{1} = W.Amp;
      case 'Phi'
        varargout{1} = W.Phi;
      case 'Re'
        varargout{1} = Re(W);
      case 'Im'
        varargout{1} = Im(W);
      case 'Complex'
        varargout{1} = Complex(W);
      case 'StartTime'
        varargout{1} = W.Time(1);
      case 'EndTime'
        varargout{1} = W.Time(end);
      case 'TimeStep'
        varargout{1} = min(diff(W.Time));
      case 'Omega'
        varargout{1} = Omega(W);
      case 'OmegaDot'
        varargout{1} = OmegaDot(W);
      case 'Flux'
        varargout{1} = Flux(W);
      otherwise
        error('Waveform subsref: Invalid field name');
    end;
    
  case '{}'
    error('Cell array indexing not supported by Waveform objects.');
    
end; % end switch

if(size(Indices, 2) > 1);
    varargout{1} = subsref(varargout{1}, Indices(1,2:end));
end;

end
