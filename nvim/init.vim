let s:curdir = fnamemodify(resolve(expand('<sfile>:p')), ':h')
let &rtp.=','.s:curdir

" Set leader key
let mapleader = ','

let $SHELL = system('which zsh')[:-2]


" Load configs
for fpath in split(globpath(expand(s:curdir.'/config'), '*.vim'), '\n')
  exe 'source' fpath
endfor

" Option Setup===========================================================
syntax on

set nocompatible           " 關閉 vim 的舊版相容模式，才能使用新功能
set t_Co=256               " 支援 256 色
set title                  " 在 Terminal 標題顯示目前的路徑和檔名
set number                 " 顯示行號
set cursorline             " 顯示游標所在的行數
hi CursorLine cterm=NONE ctermbg=234 ctermfg=NONE " 設定 Cursorline 的樣式
hi LineNr cterm=NONE ctermfg=DarkGrey ctermbg=NONE " 設定 LineNr 的樣式
set ruler                  " 在右下角顯示目前的行數、列數
set encoding=utf-8         " 以 UTF-8 顯示
set fileencoding=utf-8     " 以 UTF-8 開啟/儲存檔案
set noshowmatch            " no凸顯對應的括號
set showmode               " 顯示模式

set tabstop=4
set softtabstop=4          " 這兩個是設置 tab 寬度為 4，預設的 tab 太寬了
set shiftwidth=4           " 手動縮排的寬度也設為 4
set smartindent            " 開啟自動縮排

set list listchars=tab:→\ ,eol:↲,trail:·,extends:»,precedes:«,nbsp:× " 設定特殊符號要顯示的字元。 tab、行尾與多餘空白

set ai                     " 換行時自動縮排
set background=dark        " 設定暗色背景（有些配色主題需要此設定）
set backspace=2            " 在 insert 模式啟用 backspace 鍵
set history=100            " 保留 100 個使用過的指令
" :set expandtab              " 輸入 tab 都會被轉換成 space，而對應的 space 數量由 :set tabstop=x 決定
set guifont=Fira\ Code:h12 " 把預設的字體改成 Fira Code，字級大小 12
set nowrap                 " 設定單行文字不隨視窗大小折行

filetype indent on         " 啟用依照檔案類型，決定自動縮排樣式的功能

set showcmd                " （在右下角）顯示現有的命令
