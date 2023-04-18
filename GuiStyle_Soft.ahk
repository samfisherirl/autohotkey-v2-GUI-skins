#NoEnv
#SingleInstance force
pr:= a_scriptdir . "\SkinH_EL.dll"
IniRead, aa1, C:\Users\dower\Downloads\skinsharp-main\skinsharp-main\RSSINI.ini , A1 , Key1
aa1:= aa1
SkinForm(Apply,pr,aa1)

OnExit, GetOut
Gui,2: add, button,xm w100 h40, Button
Gui,2: add, edit, xm y+20 w100 h20, Edit
Gui,2: add, listbox,xm y+20, ListBox
Gui,2: add, checkbox,xm y+20, checkbox
Gui,2: add, DDL, xm y+20, DropDownList
Gui,2: Show, w200 , GUI_Style
return
;-----------------------------------

GetOut:
2GuiClose:
Gui,2: Hide
SkinForm(0)
ExitApp
;-----------------------------------

SkinForm(Param1 = "Apply", DLL = "", SkinName = ""){
    if(Param1 = Apply){
        DllCall("LoadLibrary", str, DLL)
        DllCall(DLL . "\SkinH_AttachEx", AStr,SkinName, Str,"mhgd")
    }else if(Param1 = 0){
        DllCall(DLL . "\USkinExit")
        }
}