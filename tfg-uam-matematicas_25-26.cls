\ProvidesClass{tfg-uam}[2025/10/20 v1 LaTeX document class]
%
%
\newif\iflisttables\listtablesfalse
\newif\iflistfigures\listfiguresfalse
\DeclareOption{spanish}{\PassOptionsToPackage{english,main=spanish}{babel}}
\DeclareOption{english}{\PassOptionsToPackage{spanish,main=english}{babel}}
\DeclareOption{listoftables}{\listtablestrue}
\DeclareOption{listoffigures}{\listfigurestrue}
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{book}}
\ProcessOptions
\LoadClass{book}

\RequirePackage[T1]{fontenc}
\RequirePackage{babel}

\RequirePackage[a4paper,left=3.4cm,right=3.4cm,top=3.8cm,bottom=3.8cm]{geometry}

\RequirePackage{url}
\RequirePackage[dvipsnames]{xcolor}

\clubpenalty=10000
\widowpenalty=10000


\newcommand{\tutor}[1]{\newcommand{\t@tor}{#1}}
\newcommand{\curso}[1]{\newcommand{\c@rs}{#1}}

\newcommand{\titulacioname}{Grado en Matem\'aticas}
\newcommand{\tfgname}{Trabajo de fin de grado}

\newcommand{\authorname}{Autor}
\newcommand{\tutorname}{Tutor}
\newcommand{\coursename}{Curso}
\newcommand{\keywordsname}{Palabras clave}


\newcommand{\appendicesname}{Ap\'endices}


\addto\captionsspanish{%
     \renewcommand{\titulacioname}{Grado en Matem\'aticas}
     \renewcommand{\tfgname}{Trabajo de fin de grado}
     \renewcommand{\authorname}{Autor}
     \renewcommand{\tutorname}{Tutor}
     \renewcommand{\coursename}{Curso}
     \renewcommand{\keywordsname}{Palabras clave}
     \renewcommand{\tablename}{Tabla}
     \renewcommand{\listtablename}{\'Indice de tablas}
     \renewcommand{\appendicesname}{Ap\'endices}}
     
\addto\captionsenglish{%
     \renewcommand{\titulacioname}{Degree in Mathematics}
     \renewcommand{\tfgname}{}
     \renewcommand{\authorname}{Author}
     \renewcommand{\tutorname}{Tutor}
     \renewcommand{\coursename}{Course}
     \renewcommand{\keywordsname}{Keywords}
     \renewcommand{\appendicesname}{Appendices}}
     

\RequirePackage{titlesec}

\titlelabel{\thetitle.\quad}

\titleformat{\chapter}[display]
{\normalfont\Large\filleft\bfseries}  % FORMAT
{\LARGE\MakeUppercase{\chaptertitlename} \thechapter} % LABEL
{0pc}                                                 % SEP
{\Huge}                                               % BEFORE CODE 
[\vspace{5pt}{\titlerule[1pt]}]                       % AFTER  CODE 



\RequirePackage{tocloft}
%
\setlength{\cftbeforechapskip}{3pt}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Definición de las cabeceras y pies de página
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\RequirePackage{fancyhdr}
\setlength{\headheight}{16pt}
\renewcommand*{\headrulewidth}{0.7pt}

\renewcommand{\chaptermark}[1]{\markboth{{\sffamily\mdseries\normalsize\hspace{1em} #1}}{}}
\renewcommand{\sectionmark}[1]{\markright{{\sffamily\mdseries\normalsize\thesection\hspace{0.5em} #1}}{}}

\lhead[\bfseries\thepage]{\sffamily\rightmark}
\rhead[\sffamily\leftmark]{\bfseries\thepage}
\cfoot{} 
\lfoot{}
\rfoot{}
%%%Comandos para fijar un tope de páginas (40 por defecto)
\newcounter{tope}\setcounter{tope}{40}%
\def\vertical{\color{white}\rule[2\baselineskip]{4pt}{1\textheight}}
\def\tachadura{\begin{minipage}[b][0pt]{0pt}{\vertical}\end{minipage}}
\def\aviso{\large\color{red} Material que no se leerá por superar el n\'umero máximo de p\'aginas}
\def\chapter{
	\if@openright 
	\ifodd\thepage%Si se va a generar una en blanco se aumenta tope
	\global\stepcounter{tope}\fi
	\cleardoublepage \else \clearpage \fi
	\ifnum\value{page}>\thetope
	\ifPara\gdef\marcaRE{\aviso}
	\gdef\marcaLO{\aviso}\fi 
	\global\thispagestyle{fancy}
	\else\global\thispagestyle{empty}\fi
	\@topnum \z@ \@afterindentfalse \secdef \@chapter \@schapter}
\def\capitulofancy{\if@openright \cleardoublepage \else \clearpage \fi
	\thispagestyle{fancy}\global
	\@topnum \z@ \@afterindentfalse \secdef \@chapter \@schapter *}
\newcommand{\sectionfancy}[1]{\paragraph*{\thesection\ #1\newline}}
\newcommand{\subsectionfancy}[1]{\subparagraph*{\thesubsection\ #1\newline}}
\let\oldsubsection\subsection
\let\oldsection\section
\let\oldchapter\chapter
\RequirePackage{ifthen}
\newif\ifPara\Paratrue
\newif\ifSuperado\Superadofalse
\newcounter{temp}
\def\marcaLE{\bfseries\thepage}
\def\marcaRE{\sffamily\rightmark}
\def\marcaLO{\sffamily\leftmark}
\def\marcaRO{\bfseries\thepage}
\newcommand{\tachado}{\ifPara
	\ifnum\value{page}=\thetope
	\global\Superadotrue
	\immediate\gdef\chapter{\capitulofancy}
	\gdef\section{\sectionfancy}
	\gdef\subsection{\subsectionfancy}
	\gdef\marcaRE{\aviso}
	\gdef\marcaLO{\aviso}
	\fi
	\ifnum\value{page}>\thetope
	{}\whiledo{\thetemp<45}{\stepcounter{temp}\tachadura \quad}
	\setcounter{temp}{0}
	\fi
	\fi}
\def\AnulaParada{\clearpage
	\gdef\marcaLE{\bfseries\thepage}
	\gdef\marcaRE{\sffamily\rightmark}
	\gdef\marcaLO{\sffamily\leftmark}
	\let\marcaRO\marcaLE
	\let\chapter\oldchapter
	\let\section\oldsection
	\let\subsection\oldsubsection
	\global\Parafalse
	\ifSuperado
	\setcounter{page}{\thetope}
	\stepcounter{page}\fi}
\fancyhead[LE]{\marcaLE}
\fancyhead[RE]{\marcaRE}
\fancyhead[LO]{\marcaLO}
\fancyhead[RO]{\marcaRO}
\fancyfoot[L]{\tachado}
\let\oldmainmatter\mainmatter
\def\mainmatter{\pagestyle{fancy}\oldmainmatter}
\let\oldappendix\appendix
\def\appendix{\oldappendix\if@openright \cleardoublepage \else \clearpage \fi 
		\AnulaParada\Superadofalse}
\let\oldthebibliography\thebibliography
\def\thebibliography{\AnulaParada\oldthebibliography}
%%%Hasta aquí lo del tope de páginas

\RequirePackage{graphicx}
\RequirePackage{eso-pic}
%%%%%%%%%%%%%%
%  Navegable
%%%%%%%%%%%%%
\RequirePackage[colorlinks=true, linkcolor=blue,citecolor=blue,urlcolor=blue]{hyperref}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Separación entre párrafos
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\setlength{\parskip}{0.5pt plus 1.0pt minus 0.5pt}%JL Varona
\newcommand{\foreign}[2]{\foreignlanguage{#1}{\textit{#2}}}
\newenvironment{Foreign}[1]{\begin{quote}\itshape\selectlanguage{#1}}{\end{quote}}     
      
%%%%%%%%%%%
% Resúmenes
%%%%%%%%%%%
\newenvironment{abstract}[1][esp]{%
        \begingroup
          \selectlanguage{#1}\addvspace{\baselineskip}\par\hfill
          {\sffamily\bfseries\Large\abstractname}\smallskip\par}{%
          \par\nopagebreak\noindent
          \iflanguage{english}{\endgroup\cleardoublepage\makeindexes}{\endgroup\par\vspace{\stretch{1}}}}
%%%%%%%%%
% Índices
%%%%%%%%%
\newcommand{\makeindexes}{\gdef\thepage{}\tableofcontents\cleardoublepage
                          \iflistfigures\listoffigures\fi
                          \iflisttables\listoftables\fi
                          \addtocontents{toc}{\protect\noindent\protect\hrulefill\protect\par}
                          }

%%%%%%%%%%
% Portada
%%%%%%%%%%
\newcommand{\m@ketitle}{%
\begin{titlepage}
\AddToShipoutPicture*{\AtPageUpperLeft{%
    % Márgenes:  
    \raisebox{-4cm}{
    %\hspace{2cm}
    \hspace{3cm}
    \includegraphics[height=2.5cm]{media/logoUAM.png}%
    %\hspace{1.5cm}
    %\includegraphics[height=1.5cm]{media/logoUAM.png}% 
    \hspace{6cm}% 21cm-(2+6.27+5.19+2)cm
    %\hspace{3.2cm}
    \includegraphics[height=2.5cm]{media/logoCiencias.png}% 
    }}}

\AddToShipoutPicture*{{\color[cmyk]{.85,0,1,.1}\rule{21cm}{40pt}}}%Verde

\centering
\vspace*{2.4\baselineskip}

\scalebox{1.2}{\scshape\bfseries\Large Universidad Autónoma de Madrid}

\vspace*{.5\baselineskip}

\scalebox{1.2}{\scshape\bfseries\Large Facultad de Ciencias}

\vspace*{5\baselineskip}

\scalebox{1.5}{\scshape\bfseries\Large \titulacioname}

\vspace*{1.5\baselineskip}

\scalebox{1.2}{\scshape\bfseries\Large \tfgname}


\vspace*{6\baselineskip}

\scalebox{1.6}{\begin{minipage}[c][2\baselineskip][c]{.6\textwidth}
		\centering\bfseries\Large\@title%
		\\*[.5\baselineskip]
		\centering\bfseries\normalsize\@author%
	\end{minipage}}

\vfill 

\begin{flushright}
\scalebox{1.2}{\bfseries\Large\coursename\space\c@rs}
\end{flushright}
\end{titlepage}}
%%%Fin de la portada

%%%%%%%%%%%%%%%%%
\renewcommand{\cleardoublepage}{\clearpage\if@twoside \ifodd\c@page\else
\hbox{}
\thispagestyle{empty}
\newpage
\if@twocolumn\hbox{}\newpage\fi\fi\fi}
\renewcommand{\frontmatter}{\cleardoublepage\@mainmatterfalse\pagestyle{empty}}
\AtBeginDocument{%
    \frontmatter\m@ketitle\cleardoublepage%\thispagestyle{empty}
    }

\newcounter{appendix}
\AtEndDocument{%
    \ifnum\value{chapter}=1 
           \immediate\write\@auxout{\unexpanded{\setcounter{appendix}{1}}}
    \else 
           \immediate\write\@auxout{\unexpanded{\setcounter{appendix}{2}}} \fi}
