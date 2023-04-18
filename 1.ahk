;AutoGUI 2.5.8 

; x := "skinh.she"
; dp :=  A_ScriptDir . "\SkinHu.dll"
#SingleInstance Force
hSkinH := DllCall("LoadLibrary", "Str", "SkinH_EL.dll")
DllCall("SkinH_EL.dll_AttachEx", "Str", A_ScriptDir "\aero.she")

; REMOVED: #NoEnv

SetWorkingDir(A_ScriptDir)

; REMOVED: SetBatchLines -1

myGui := Gui()

myGui.Add("CheckBox", "x130 y187 w120 h23", "CheckBox")

myGui.Add("GroupBox", "x403 y100 w120 h80", "GroupBox")

myGui.Title := "Window"

myGui.Show("w620 h420")

Return

GuiEscape(*)

{ ; V1toV2: Added bracket

GuiClose:

    ExitApp()

} ; Added bracket in the end

