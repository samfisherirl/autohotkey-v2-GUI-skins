; place this anywhere
; uncomment to set or use in another file
; setTheme(theme := "aero.she")

ahkexe := A_ScriptDir "\AutoHotkey32UIA.exe"

; if not 32 bit, launch 32bit ahk
if !(1 = 1 and A_PtrSize = 4)
{
	Run(ahkexe " `"" A_ScriptFullPath "`"") ;Must run 32bit
	; Run either 32bit AHKV2
	ExitApp()
}

setTheme(theme := "aero.she"){
	hSkinH := DllCall("LoadLibrary", "Str", "skins\SkinHu.dll")
	changeSkin(A_ScriptDir "\skins\" theme)
}

changeSkin(skinPath) {
	DllCall("SkinHu\SkinH_AttachEx", "Str", skinPath, "Str", "mhgd")
}
