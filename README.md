# libft

42 본 과정의 첫 프로젝트. 표준 C 라이브러리(`libc`)와 자주 쓰는 보조 유틸 함수들을 직접 구현하고, `ar`로 묶어 정적 라이브러리 **`libft.a`** 를 만든다. 이후 본 과정의 거의 모든 C 프로젝트에서 이 라이브러리를 끌어다 쓰게 된다.

> 원본 과제 명세: [`subject.pdf`](./subject.pdf) (영문)

## 과제 개요 / 요구사항

- **언어**: C
- **결과물**: `libft.a` (정적 라이브러리)
- **빌드 도구**: 직접 작성한 `Makefile`만 사용 (`libtool`·외부 빌드 시스템 금지)
- **구성**
  - **Part 1 — libc 재구현**: 표준 헤더의 함수들을 시그니처 그대로 재구현 (`ft_` 접두사)
  - **Part 2 — 추가 함수**: 표준 libc에는 없지만 향후 프로젝트에서 자주 쓸 문자열·출력 유틸
  - **Bonus — 연결 리스트**: `t_list` 구조체와 그 위에서 동작하는 9개 함수
- **공통 제약**
  - **Norminette** 통과 필수 (함수 25줄·파일 5함수·금지 키워드 등)
  - 허용 함수: `malloc`, `free`, `write`, `read` 등 subject 명시 함수만
  - **전역 변수 금지**, 보조 함수는 `static`으로 분리
  - `ar` 명령어로 라이브러리 생성 (`libtool` 금지)

## 구현된 함수

### Part 1 — libc

| 메모리 | 문자열 | 문자 분류·변환 | 변환·할당 |
|---|---|---|---|
| `ft_memset` | `ft_strlen` | `ft_isalpha` | `ft_atoi` |
| `ft_bzero` | `ft_strlcpy` | `ft_isdigit` | `ft_calloc` |
| `ft_memcpy` | `ft_strlcat` | `ft_isalnum` | `ft_strdup` |
| `ft_memccpy` | `ft_strchr` | `ft_isascii` | |
| `ft_memmove` | `ft_strrchr` | `ft_isprint` | |
| `ft_memchr` | `ft_strnstr` | `ft_toupper` | |
| `ft_memcmp` | `ft_strncmp` | `ft_tolower` | |

### Part 2 — 추가 함수

`ft_substr` · `ft_strjoin` · `ft_strtrim` · `ft_split` · `ft_itoa` · `ft_strmapi` · `ft_putchar_fd` · `ft_putstr_fd` · `ft_putendl_fd` · `ft_putnbr_fd`

### Bonus — 연결 리스트

```c
typedef struct s_list {
    void          *content;
    struct s_list *next;
}                t_list;
```

`ft_lstnew` · `ft_lstadd_front` · `ft_lstadd_back` · `ft_lstsize` · `ft_lstlast` · `ft_lstdelone` · `ft_lstclear` · `ft_lstiter` · `ft_lstmap`

## 풀이 노트

- **`ft_memmove` — 오버랩 처리**: `src`와 `dst`가 겹칠 때 단순 정방향 복사로 데이터가 깨지는 케이스가 핵심. `dst > src`이면 끝에서부터 역방향으로 복사하고, 그 외엔 정방향. `memcpy`와 다른 결정적 차이.
- **`ft_strlcpy` / `ft_strlcat` — BSD 시맨틱**: 리턴값은 "복사된 길이"가 아니라 **시도된 전체 길이**(`dstsize`가 부족해도). `dstsize == 0`일 때 dst를 건드리지 않고 src 길이만 반환하는 점이 함정.
- **`ft_calloc` — 곱셈 오버플로**: `count * size`가 `size_t`를 넘기면 `NULL`을 반환해야 하지만, 채점기 버전에 따라 요구가 갈리므로 안전 측으로 검증.
- **`ft_itoa` — `INT_MIN` 케이스**: 음수를 양수로 뒤집어 자릿수를 세는 단순 구현은 `-2147483648`에서 오버플로. 음수 부호를 떼지 않거나 long으로 잠깐 승격하는 식으로 우회.
- **`ft_split` — 부분 실패 처리**: 단어를 하나씩 `malloc`하다 도중에 실패하면 **이미 할당한 단어들을 모두 `free`** 한 뒤 `NULL` 반환. 누수 없는 분기 처리가 핵심.
- **`ft_substr` — 경계 케이스**: `start`가 `ft_strlen(s)`을 넘으면 빈 문자열 반환, 자르려는 길이가 원본을 넘으면 끝까지만.
- **`ft_lstmap` — 트랜잭션 시맨틱**: `f`가 도중에 실패하면 지금까지 새로 만든 노드들을 모두 `del`로 해제하고 `NULL` 반환. mandatory의 `ft_split`과 같은 누적 정리 패턴.
- **Makefile — `make bonus`**: mandatory 오브젝트만 먼저 `ar`로 묶은 뒤 bonus 오브젝트를 동일 `.a`에 **추가** 아카이브. mandatory 빌드를 깨지 않으면서 보너스 함수만 선택적으로 포함시키는 구조.

## 빌드 / 사용법

```sh
# 기본 빌드 (mandatory만)
make            # → libft.a

# 보너스 포함
make bonus      # → libft.a (lst* 함수 추가)

# 정리
make clean      # .o 제거
make fclean     # libft.a까지 제거
make re         # fclean + all
```

다른 프로젝트에서 사용:

```sh
# 디렉토리 구조 예시
project/
├── libft/        ← 이 레포
│   ├── libft.a
│   └── libft.h
├── main.c
└── Makefile

# 컴파일
cc main.c -L./libft -lft -I./libft -o app
```

## 메모

- `libft_memo.rtfd/` 는 학습 당시 정리한 함수 메모(rtf + 스크린샷). 참고용으로 그대로 보존.
- `ft_striteri`는 본 레포에 없으며, 이는 당시 subject 버전이 해당 함수를 요구하지 않은 결과. 이후 버전의 libft에선 mandatory에 포함된다.
- `ft_memccpy`는 표준 libft 후기 버전에선 빠졌지만 본 레포에는 포함 — 당시 subject 기준.
- `subject.pdf`는 [Ian-Orwel/42-Cursus-Subjects](https://github.com/Ian-Orwel/42-Cursus-Subjects/tree/main/Cursus/libft)의 영문 판본을 가져온 것.
