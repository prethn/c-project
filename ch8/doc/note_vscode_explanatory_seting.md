# 在vscode快捷键来输入注释模版（cpp）
>1. ctrl + shift + p --> input: configure user snippets  
>2. Add the following code at the end
```json
	"C++ Multi-line Comment Template": {
        "prefix": "cppcomment",
		"body": [
            "/**",
		  " * @brief: $1",
		  " *",
		  " * @param: $2",
		  " * @return: $3",
		  " *",
		  " * @author: prethn",
		  " * @date: ${CURRENT_YEAR}-${CURRENT_MONTH}-${CURRENT_DATE} | ${CURRENT_HOUR}:${CURRENT_MINUTE}:${CURRENT_SECOND}",
		  " */"
		],
		"description": "Inserts a C++ multi-line comment template"
	  }
 ```
>3. Add Extension of Multi Command 
>4. ctrl + shift + p --> input:  Open Settings (JSON)
>5. Add the following code at the end
```json
"multiCommand.commands": [
    {
        "command": "multiCommand.insertCppCommentTemplate",
    "sequence": [
        {
            "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
          "name": "C++ Multi-line Comment Template"
        }
      }
    ]
  }
]
```
>6. ctrl + shift + p --> input:  Open keyboard shortcuts (JSON)
>7. Add the following code at the end
```json
  {
    "key": "ctrl+alt+c",
    "command": "extension.multiCommand.execute",
    "args": { "command": "multiCommand.insertCppCommentTemplate" },
    "when": "editorTextFocus && editorLangId == cpp"
  }
```
> Attention：Pay attention to adding comma ！！