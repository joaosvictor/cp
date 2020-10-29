" Disable menus:
set guioptions-=r
set guioptions-=T

" Disable backups:
set nobackup
set noswapfile
set nowritebackup

" colors and themes:
colorscheme angr
filetype on
syntax on
highlight Comment ctermfg = green
 
" System clipboard:
set clipboard=unnamed

" Tabss: 
set expandtab
set shiftwidth=4
set tabstop=4

" indentation:
filetype plugin indent on
set autoindent

" Ruler, break and number of lines:
set linebreak
set number
set ruler

" Tabbed browsing:
map <C-Tab> :tabnext<CR>
map <S-Tab> :tabprevious<CR>

" Search:
set hlsearch
set ignorecase
set incsearch

" Clean the searched results:
nmap <silent> <C-C> :silent noh<CR>








"BELOW IS THE WINDOWS SET UP FOR PYTHON AND C++

" Python:
"autocmd FileType python map <buffer> <F2> :w<CR>:exec '!python' shellescape(@%, 1)<CR>
"autocmd FileType python imap <buffer> <F2> <esc>:w<CR>:exec '!python' shellescape(@%, 1)<CR>

" C++:
"nnoremap <c-z> :!g++ -o %:r.out %<enter><enter>
"nnoremap <c-x> :!%:r.out<enter><enter>
