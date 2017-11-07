# Info  
Rewrite of: [OGLeague2](https://github.com/moonshadow565/OGLeague2)  
# Compiling  
Requires c++17 support and cmake.  
To use in Visual Studio 2017: File > Open Folder > ogleague folder  
# Code Style & Formating  
Uses ``clang-format``!  
Visual studio how-to:  
1. Get extension: Tools  Extensions And Updates Online Search for  [ ClangFormat](https://marketplace.visualstudio.com/items?itemName=LLVMExtensions.ClangFormat)  
2.  Tools > Options > LLVM/Clang > ClangFormat  
3.  Set Format On Save > Enable to ``True``  
4.  Set Format Options > Fallback Style to ``none``  
5.  Set Format Options > Style to ``file``  
This will make Visual Studio only use ``clang-format`` when ``.clang-format`` file is present in project and also autoformat on saving the file.  
