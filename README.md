# Neurset
Neurset is a direct neurofeedback EEG device designed and developed by Josh, Aleksey, Liam, and Ryan
## Contributors
- **Josh Saikali**
- **Aleksey Dosov**
- **Liam Kelleher**
- **Ryan McDonald**

## Contributions
### Josh:
Use Case Diagrams,
PCDevice,
EEGHeadset,
EEGNode,
NeuroDeviceController,
MainWindow

### Aleksey:
UML Class Diagrams,
Display,
ContactLost,
NeuroDeviceController,
MainWindow

### Liam:
Use Case Diagrams,
Session,
SessionLog,
SessionManager,
Waveform,
LightIndicator,
Treatment,
NeuroDeviceController,
MainWindow

### Ryan:
State Diagrams,
Session,
NeuroDeviceController,
MainWindow

## MainWindow:
Handles user input and all UI components outside the main device

## PCDevice:
External UI that shows detailed information of uploaded session logs

## NeuroDeviceController:
Contains the main communication paths between all other components

## Display:
Handles updating the main device display

## Display:
Handles updating the main device display

## LightIndicator:
Handles updating the main device lights

## Treatment:
Handles the treatment logic and execution

## EEGHeadset:
Contains all the nodes and communicates with the NeuroDeviceController

## EEGNode:
Handle generating and returning the EEG signals

## Waveform:
Contains the EEG signals and their components

## SessionManager:
Manages the sessions and session logs

## SessionLog:
Contains all past sessions

## Session:
Contains information about the treatment
