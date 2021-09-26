source "$HOME/.zinit/bin/zinit.zsh"

# If you come from bash you might have to change your $PATH.
export PATH=$PATH:$HOME/bin:/usr/bin

POWERLEVEL9K_MODE='nerdfont-complete'
POWERLEVEL9K_TRANSIENT_PROMPT=same-dir
POWERLEVEL9K_INSTANT_PROMPT=verbose
POWERLEVEL9K_DISABLE_HOT_RELOAD=true

# battery
POWERLEVEL9K_BATTERY_CHARGED_BACKGROUND='46'
POWERLEVEL9K_BATTERY_CHARGED_FOREGROUND='235'
POWERLEVEL9K_BATTERY_CHARGED_ICON='/UF240'
POWERLEVEL9K_BATTERY_CHARGING_ICON='/UF240'
POWERLEVEL9K_BATTERY_CHARGING_BACKGROUND='178'
POWERLEVEL9K_BATTERY_CHARGING_FOREGROUND='235'
POWERLEVEL9K_BATTERY_LOW_THRESHOLD='10'
POWERLEVEL9K_BATTERY_LOW_BACKGROUND='203'
POWERLEVEL9K_BATTERY_LOW_FOREGROUND='245'
POWERLEVEL9K_BATTERY_LOW_ICON='/UF240'
POWERLEVEL9K_BATTERY_DISCONNECTED='$DEFAULT_COLOR'
POWERLEVEL9K_BATTERY_VERBOSE=false
POWERLEVEL9K_BATTERY_ICON=' \uf1e6 '

# time
POWERLEVEL9K_TIME_FORMAT="%D{%m.%d %H:%M}"

# cpu load
#POWERLEVEL9K_LOAD_CRITICAL_BACKGROUND="white"
#POWERLEVEL9K_LOAD_WARNING_BACKGROUND="white"
#POWERLEVEL9K_LOAD_NORMAL_BACKGROUND="white"
#POWERLEVEL9K_LOAD_CRITICAL_FOREGROUND="deeppink2"
#POWERLEVEL9K_LOAD_WARNING_FOREGROUND="yellow"
#POWERLEVEL9K_LOAD_NORMAL_FOREGROUND="black"
#POWERLEVEL9K_LOAD_CRITICAL_VISUAL_IDENTIFIER_COLOR="deeppink2"
#POWERLEVEL9K_LOAD_WARNING_VISUAL_IDENTIFIER_COLOR="yellow"
#POWERLEVEL9K_LOAD_NORMAL_VISUAL_IDENTIFIER_COLOR="green"

# status
POWERLEVEL9K_STATUS_VERBOSE=false
POWERLEVEL9K_STATUS_CROSS=true

# USER
POWERLEVEL9K_ALWAYS_SHOW_USER=true
POWERLEVEL9K_CONTEXT_TEMPLATE="%n"
POWERLEVEL9K_CONTEXT_FOREGROUND='white'

# dir
POWERLEVEL9K_DIR_BACKGROUND='blue'

# prompt
POWERLEVEL9K_PROMPT_ON_NEWLINE=true
POWERLEVEL9K_PROMPT_ADD_NEWLINE=true
POWERLEVEL9K_RPROMPT_ON_NEWLINE=true
POWERLEVEL9K_RPROMPT_ICON_LEFT=true
POWERLEVEL9K_LEFT_PROMPT_ELEMENTS=(os_icon context root_indicator anaconda dir dir_writable vcs)
POWERLEVEL9K_RIGHT_PROMPT_ELEMENTS=(status command_execution_time background_jobs vpn_ip public_ip time battery)

# prompt prefix
POWERLEVEL9K_MULTILINE_FIRST_PROMPT_PREFIX="%F{blue}\u256D\u2500%F\uE0B6"
POWERLEVEL9K_MULTILINE_LAST_PROMPT_PREFIX="%F{blue}\u2570\uf460%F{white} "
#POWERLEVEL9K_MULTILINE_LAST_PROMPT_PREFIX="%{%b%f%k%F{blue}%} %{%f%}"
POWERLEVEL9K_MULTILINE_FIRST_PROMPT_SUFFIX="%F{blue}\uF47D\u2500\u256E"
#\uf459
POWERLEVEL9K_MULTILINE_LAST_PROMPT_SUFFIX="%F{blue}\uE0B4\u256F"

# anaconda
POWERLEVEL9K_ANACONDA_LEFT_DELIMITER="\b\ue0bd "
POWERLEVEL9K_ANACONDA_RIGHT_DELIMITER=""
POWERLEVEL9K_ANACONDA_BACKGROUND='orange1'
POWERLEVEL9K_PYTHON_ICON="\ue606"



# zplugin/zinit
zinit ice depth=1;
zinit light romkatv/powerlevel10k

zinit ice lucid wait='0' atinit='zpcompinit'
zinit light "zdharma/fast-syntax-highlighting"

zinit ice lucid wait="0" atload='_zsh_autosuggest_start'
zinit light zsh-users/zsh-autosuggestions

zinit ice lucid wait='0'
zinit light zsh-users/zsh-completions

zinit snippet OMZ::plugins/sudo/sudo.plugin.zsh
#zinit snippet OMZ::plugins/battery/battery.plugin.zsh
zinit snippet OMZ::plugins/common-aliases/common-aliases.plugin.zsh
zinit snippet OMZ::plugins/autojump/autojump.plugin.zsh

zinit ice lucid wait='1'
zinit snippet OMZ::plugins/git/git.plugin.zsh

zinit light chrissicool/zsh-256color

zinit light esc/conda-zsh-completion



# zsh completion
zstyle ':completion:*' matcher-list 'm:{a-za-z}={a-za-z}' \
    'r:|[._-]=* r:|=*' 'l:|=* r:|=*'
zstyle ':completion:*' menu yes select
autoload -Uz compinit && compinit

# aliases
if [ -f ~/.shell_aliases ]; then
    . ~/.shell_aliases
fi


# JAVA
export JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64
export JRE_HOME=$JAVA_HOME/jre
export PATH=$PATH:$JAVA_HOME/bin:$JRE_HOME/bin
export CLASSPATH=$CLASSPATH:.:$JAVA_HOME/lib:$JRE_HOME/lib

# Python
# export PYENV_ROOT="$HOME/.pyenv"
# export PATH="$PYENV_ROOT/bin:$PATH"
# eval "$(pyenv init -)"
# eval "$(pyenv virtualenv-init -)"

# Android
export ANDROID_HOME="$HOME/Android/Sdk"
export PATH=$PATH:/opt/android-studio/bin

# Flutter
export PATH=$PATH:$HOME/development/flutter/bin

# Texlive
export MANPATH=$MANPATH:/usr/local/texlive/2020/texmf-dist/doc/man
export INFOPATH=$INFOPATH:/usr/local/texlive/2020/texmf-dist/doc/info
export PATH=$PATH:/usr/local/texlive/2020/bin/x86_64-linux


# Added by Zinit's installer
if [[ ! -f $HOME/.zinit/bin/zinit.zsh ]]; then
    print -P "%F{33}▓▒░ %F{220}Installing %F{33}DHARMA%F{220} Initiative Plugin Manager (%F{33}zdharma/zinit%F{220})…%f"
    command mkdir -p "$HOME/.zinit" && command chmod g-rwX "$HOME/.zinit"
    command git clone https://github.com/zdharma/zinit "$HOME/.zinit/bin" && \
        print -P "%F{33}▓▒░ %F{34}Installation successful.%f%b" || \
        print -P "%F{160}▓▒░ The clone has failed.%f%b"
fi

autoload -Uz _zinit
(( ${+_comps} )) && _comps[zinit]=_zinit

# Load a few important annexes, without Turbo
# (this is currently required for annexes)
zinit light-mode for \
    zinit-zsh/z-a-rust \
    zinit-zsh/z-a-as-monitor \
    zinit-zsh/z-a-patch-dl \
    zinit-zsh/z-a-bin-gem-node

# End of Zinit's installer chunk



# load some bin
zinit light zinit-zsh/z-a-bin-gem-node

zinit as="null" wait="1" lucid from="gh-r" for \
    mv="exa* -> exa" sbin       ogham/exa \
    mv="*/rg -> rg"  sbin		BurntSushi/ripgrep \
    mv="fd* -> fd"   sbin="fd/fd"  @sharkdp/fd \
    sbin="fzf"       junegunn/fzf-bin

# load some completion
zinit ice mv="*.zsh -> _fzf" as="completion"
zinit snippet 'https://github.com/junegunn/fzf/blob/master/shell/completion.zsh'
zinit snippet 'https://github.com/junegunn/fzf/blob/master/shell/key-bindings.zsh'
zinit ice as="completion"
zinit snippet 'https://github.com/robbyrussell/oh-my-zsh/blob/master/plugins/fd/_fd'
zinit ice mv="*.zsh -> _exa" as="completion"
zinit snippet 'https://github.com/ogham/exa/blob/master/completions/completions.zsh'

# no ls, yes exa
DISABLE_LS_COLORS=true

# use fd for fzf
export FZF_DEFAULT_COMMAND='fd --type f'

# End of load



# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/home/harry90/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/home/harry90/anaconda3/etc/profile.d/conda.sh" ]; then
        . "/home/harry90/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="/home/harry90/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<

export PATH=/usr/local/cuda-11.2/bin${PATH:+:${PATH}}
export LD_LIBRARY_PATH=/usr/local/cuda-11.2/lib64\${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}

eval "conda deactivate"
