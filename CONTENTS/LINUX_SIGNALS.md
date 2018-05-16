번호|신호 이름|기본처리|발생조건
----|--------|-------|--------
1|SIGHUP|종료|터미널과 연결이 끊어졌을때
2|SIGINT|종료|인터럽트로 ctrl + c 입력시
3|SIGQUIT|코어 덤프|ctrl + \ 입력시
4|SIGLL|코어 덤프|잘못된 명령 사용
5|SIGTRAP|코어 덤프|trace, breakpoint에서 TRAP 발생
6|SIGABRT|코어 덤프|abort(비정상종료) 함수에 의해 발생
7|SIGBUS|코어 덤프|버스 오류시
8|SIGFPE|코어 덤프|Floating-point exception
9|SIGKILL|종료|강제 종료시
10|SIGUSR1|종료|사용자 정의 시그널1
11|SIGSEGV|코어 덤프|세그먼테이션 폴트 시
12|SIGUSR2|종료|사용자 정의 시그널2
13|SIGPIPE|코어 덤프|파이프 처리 잘못했을때
14|SIGALRM|코어 덤프|알람에 의해 발생
15|SIGTERM|종료|Process termination
16|SIGSTKFLT|종료|Coprocessor stack error
17|SIGCHLD|무시|자식 프로세스(child process)상태 변할때
18|SIGCONT|무시|중지된 프로세스 실행시
19|SIGSTOP|중지|SIGSTOP 시그널을 받으면 SIGCONT시그널을 받을때까지 프로세스 중지
20|SIGSTP|중지|ctrl + z 입력시
21|SIGTTIN|중지|Background process requires input
22|SIGTTOU|중지|Background process requires output
23|SIGURG|무시|Urgent condition on socket
24|SIGXCPU|코어 덤프|CPU time limit exceeded
25|SIGXFSZ|코어 덤프|File size limit exceeded
26|SIGVTALRM|종료|가상 타이머 종료시
27|SIGPROF|종료|Profile timer clock
28|SIGWINCH|무시|Window resizing
29|SIGIO|종료|I/O now possible
30|SIGPWR|종료|Power supply failure
31|SIGSYS|코어 덤프|system call 잘못했을때


