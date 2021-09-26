:set directory=/tmp

"-----------------------------------------
" Automatically install missing plugins on startup
"-----------------------------------------
autocmd VimEnter *
      \  if len(filter(values(g:plugs), '!isdirectory(v:val.dir)'))
      \|   PlugInstall --sync | q
      \| endif
"-----------------------------------------
"-----------------------------------------
" Plugins
"-----------------------------------------
silent! if plug#begin('~/.vim/plugged')

Plug 'neoclide/coc.nvim', {'branch': 'release'}

Plug 'preservim/nerdtree'
Plug 'preservim/nerdtree' |
            \ Plug 'Xuyuanp/nerdtree-git-plugin'
Plug 'ryanoasis/vim-devicons'
Plug 'tiagofumo/vim-nerdtree-syntax-highlight'
Plug 'scrooloose/nerdtree-project-plugin'
Plug 'PhilRunninger/nerdtree-visual-selection'

Plug 'Yggdroot/LeaderF', { 'do': './install.sh' }

Plug 'jiangmiao/auto-pairs'
au Filetype FILETYPE let b:AutoPairs = {"(": ")"}
au FileType php let b:AutoPairs = AutoPairsDefine({'<?' : '?>', '<?php': '?>'})

Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
set laststatus=2                              " 永遠顯示狀態欄
let g:airline_powerline_fonts = 1             " 支持powerline字體
let g:airline#extensions#tabline#enabled = 1  " 顯示tab和buffer
let g:airline_theme='cobalt2'                  " vim-airline主題
if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif
let g:airline_left_sep = ''
let g:airline_left_alt_sep = '❯'
let g:airline_right_sep = ''
let g:airline_right_alt_sep = '❮'
let g:airline_symbols.branch = '⎇'

call plug#end()
endif
