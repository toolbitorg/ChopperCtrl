How to modify project property to support WxWidgets


C/C++ -> General -> Additional Include Directories
Add the following line
..\include;..\..\lib\wxWidgets-master\include;..\..\lib\wxWidgets-master\lib\vc_lib\mswud


Linker -> General -> Additional Library Directories
Add the following line
..\..\lib\wxWidgets-master\lib\vc_lib


Linker -> Input -> Additional Dependencies
Add the following line
wxmsw31ud_core.lib;wxbase31ud.lib;wxtiffd.lib;wxjpegd.lib;wxpngd.lib;wxzlibd.lib;wxregexud.lib;wxexpatd.lib;winmm.lib;comctl32.lib;rpcrt4.lib;wsock32.lib;wininet.lib;%(AdditionalDependencies)


