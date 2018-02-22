## PathEditor
### Dowload
Download the [latest beta](https://github.com/ke260g/PathEditor/releases/tag/Beta-1.2.0).

### Basic
+ just clicked the PathEditor.exe.
+ Administrative privileges are needed if you want to access or change the system environment variable 'Path'.
+ friendly undo/redo buttons

### Develop
1. [Qt Creator 4.5.0 (Community)](https://www.qt.io)
2. [Qt 5.9.4 x64-msvc2017_64](https://www.qt.io)
3. [Visual Studio 2017](https://www.visualstudio.com/downloads)

---
## More Implement Details
### deploy details
+ `$>_ windeployqt.exe --release <binary file>`
+ Windeployqt may not handle compiler-runtime-dlls friendly.
+ Compiler-runtime-dlls are also needed.
	1. **vcruntime140.dll**
	2. **msvcp140.dll**
+ where to find compiler-runtime-dlls?
  `<VS2017 install dir>\VC\Tools\MSVC\14.11.25503\bin\Hostx64\x64`

### Data structure in ActionTracer to store action
+ Firstly, it used rounded vector. </br>
  but it's not convinient for implementation.
+ Then, using unlimit-vector, as the memory is not very critical nowadays.

### value of Windows Environment Variable is using 'unicode-16' encoding
+ it needs convert from string to unicode-16

### A special scenario in QPathList
+ requirement 
  1. setAll(): ActionTracer-push
  2. undo(): call setAll **without** ActionTracer-push
  3. redo(): call setAll **without** ActionTracer-push
  4. add(): ActionTracer-push
  5. setAll(): call add() in a loop **without** ActionTracer-push
  6. implement **without** 'init'-method in QPathList
+ implementation
  1. a ugly count-lock in ActionTracer
  2. undo()/redo(): lock before call setAll()
  3. setAll(): lock before call add()