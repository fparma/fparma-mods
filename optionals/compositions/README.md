The compositions are automatically parsed from \src folder. Sub folders are categories under "FPARMA" in Eden, files inside the folders are entries

The create a new composition:

1. Create the composition in Eden editor
2. Select all parts of the composition, position the camera at the "middle" of the composition
3. Press Ctrl+D and enter `[] call fpa_common_fnc_exportCfgGroups`, press "Local exec". The composition is copied to clipboard
4. Create a new file inside one of the folders in \src (or create a new folder) and paste the composition. The name of the file should be the name of the composition and it should be a .hpp file
5. Pull request that file
