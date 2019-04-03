
folder  = 'C:/data/';

%establish cerebus connection
initializeCerebus();

  
    
fName=[folder,'Crackle_',date, '_CO_cuneate_001'];
[~,fstr,ext]=fileparts(fName);

stimWord=hex2dec('60');
DBMask=hex2dec('f0');
maxWait=400;%maximum interval to wait before exiting
pollInterval=[0.01];%polling interval in s
chan=151;%digital input is CH151

    %% start recording:

ctr=0;
tmp=dir(folder);
while isempty(cell2mat(strfind({tmp.name},fstr))) & ctr<10
    cbmex('fileconfig',fName,'',0)
    pause(.5);
    cbmex('fileconfig',fName,'testing stimulation artifacts',1);
    pause(1);
    ctr=ctr+1;
    tmp=dir(folder);
end
if ctr==10
   warning('tried to start recording and failed') 
end
pause(10)
    %% deliver our stimuli:


h=msgbox('Central Connection is open: stimulation is running','CBmex-notifier');
btnh=findobj(h,'style','pushbutton');
set(btnh,'String','Close Connection');
set(btnh,'Position',[15 7 120 17]);

%wait for stim word via cbmex:
intertrialTimer=tic;
while(ishandle(h))
        try%see if we can get a chunk of data from the cerebus
            data=cbmex('trialdata',1);
        catch
            %maybe cbmex wasn't set to read mode yet:
            CBInitWordRead(mode);
            data=cbmex('trialdata',1);
        end
        if isempty(data)%if there wasn't anything to read, skip this poll cycle
            if ~isempty(pollInterval)
                pause(pollInterval)
            end
            continue
        else%if we found some data:

            %parse raw word data from the digital channel:
            %convert word into single byte that contains the limblab state info
            words=bitshift(bitand(hex2dec('FF00'),data{chan,3}),-8);
            words=words(logical(words));
            ts=data{chan,2}(logical(words));
            % Remove all repeated words (due to encoder data timing)
            word_indices_remove = find(diff(ts)<0.0005 & diff(words)==0)+1;
            if ~isempty(word_indices_remove)
                word_indices_keep = setxor(word_indices_remove,1:length(words));
                words = words(word_indices_keep);
            end
            if ~isempty(words)
%                 unique(words,'stable')
            end
            %check if the words we found were stim words:
            idx=find(bitand(words,DBMask)==stimWord);
            %if we found no stim words, continue:
            if isempty(idx)
                if ~isempty(pollInterval)
                    pause(pollInterval)
                end
                continue
            end
            if stimStart+trainLength>=toc(sessionTimer)
                %this is a re-throw of the same word (we usually pull the same word 3 times)
                continue
            end
            %if we got to this point we have a valid stim word; convert it
            %to a code:
            stimCode=words(idx(1));
            disp(['stimulating with code: ',num2str(stimCode)])

            %and re-set the stimStart variable
            stimStart=toc(sessionTimer);
        end
        %if we got here, then we found a stim word. use the code to issue a
        %stim command:

        fwrite(b, '1')
        pause(.5)
        fwrite(b, '0')


        if ~isempty(pollInterval)
            pause(pollInterval)
        end
end
    %% stop recording:
    cbmex('fileconfig',fName,'',0)
%     impedanceData=stimObj.testElectrodes();
%     save([folder,'impedance', tStr,num2str(j),'.mat'],'impedanceData','-v7.3')
    pause(2)
    
    if(endNumber >= 10)
        save(strcat(folder,fstr(1:end-2),'waveformsSent_',num2str(endNumber)),'waveforms');    
    else
        save(strcat(folder,fstr(1:end-1),'waveformsSent_',num2str(endNumber)),'waveforms');    
    end
end

% clear stim object and leave the function
cbmex('close')
stimObj.disconnect();
stimObj.delete()
clear stimObj

pause(2);


