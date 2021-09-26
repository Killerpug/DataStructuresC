# Debug
To debug a new program, you need to add the corresponding configurations to build(task.json) and run(launch.json). These two templates will be the equivalent of running the command "$gcc main.c another_source.c -o hello.exe". Follow the templates:
Note: Remember to erase the comments because .json doesn't accept them.

- tasks.json (build)

        ,{
            "label": "build <name>", 
            "type": "cppbuild",
            "command": "C:\\MinGW\\bin\\gcc.exe",  #Builds executable for windows
            "args": [
                "-g",
                        # List of all .c source files
                "${workspaceFolder}/<ProgramName>/<file1>.c",
                "${workspaceFolder}/<ProgramName>/<file2>.c",
                "-o",
                "${workspaceFolder}/<ProgramName>/<debug>/<output>.exe"  #output executable

            ],
            "group": "build",
            "presentation": {
                "reveal": "silent"
            },
            "problemMatcher": "$msCompile"
        }

- launch.json
        
        ,{
            "name": " Launch <name>",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/<ProgramName>/<debug>/<output>.exe", 
            "args": [],
            "stopAtEntry": true,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\MinGW\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "<label(field from tasks.json)>" #this allows to build and run 
        }