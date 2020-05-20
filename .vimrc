autocmd vimenter * NERDTree

set tabstop=8
set softtabstop=0
set shiftwidth=4
set expandtab
set smarttab

" suggestion window when you're typing if you press Ctrl + n
set wildmenu
set wildmode=list:full


" searching options: highlight while you're still typing, 
" highlight results, searches are case insensitive
set incsearch
set hlsearch
set ignorecase
set smartcase

" show the commands you're typing in the bottom right corner
set showcmd

" indentation scheme based on filetype
filetype indent on
set autoindent

" line numbering based on cursor position
set number 
set relativenumber

" syntax colors enabled
syntax on 

" we can still open a new buffer if the current buffer
" is unsaved
set hidden

" set splits to be natural
set splitbelow
set splitright

" matching brackets
"inoremap { {}<ESC>ha
"inoremap ( ()<ESC>ha
"inoremap [ []<ESC>ha

" Ctrl + c is now Escape and Escape does nothing
vnoremap <C-c> <Esc>
inoremap <C-c> <Esc>

" indenting right is just Tab, left is shift + tab
nnoremap <Right> >>
nnoremap <Left> <<

" move to window in split with just Ctrl + h, j, k, or l
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l

" Space is now the leader key
map <Space> <leader>

" save and quit
nnoremap <leader>s :w<cr>
nnoremap <leader>q :q<cr>


" change buffer with space + n or N
nnoremap <leader>l :ls<cr>
nnoremap <leader>r :registers<cr>

" buffer movement
nnoremap <leader>n :bnext<cr>
nnoremap <leader>N :bprev<cr>
nnoremap <leader>1 :b1<cr>
nnoremap <leader>2 :b2<cr>
nnoremap <leader>3 :b3<cr>
nnoremap <leader>4 :b4<cr>
nnoremap <leader>5 :b5<cr>
nnoremap <leader>6 :b6<cr>
nnoremap <leader>7 :b7<cr>
nnoremap <leader>8 :b8<cr>
nnoremap <leader>9 :b9<cr>

" page movement
nnoremap <leader>j <PageDown>
nnoremap <leader>k <PageUp>

map <F8> :!clear && cmake ./build/ -G "MSYS Makefiles" <CR>
" map F9 to compile and run the open file
" map <F9> :!clear && g++ -std=c++17 -Wfatal-errors % -o %< && ./%< <CR>
map <F9> :!clear && make -C ./build/ -j 12 <CR>


