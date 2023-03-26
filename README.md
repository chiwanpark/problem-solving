# problem-solving

온라인 알고리즘 문제 풀이 플랫폼에서 풀어봤던 문제의 소스 코드 입니다.
아래 플랫폼의 코드가 올라와 있습니다.

- [Algospot (chiwanpark)](https://algospot.com/user/profile/4747)
- [Backjoon Online Judge (chiwanpark)](https://www.acmicpc.net/user/chiwanpark), [solved.ac (chiwanpark)](https://solved.ac/profile/chiwanpark)

## 빌드

빌드 시스템은 CMake를 사용합니다.
아래 명령어로 빌드 할 수 있습니다.

```bash
mkdir build
cd build
cmake ..
make
```

## 코드 포맷팅

이 레포지토리의 모든 C/C++ 소스코드는 LLVM 코드 스타일에 가로 폭 제한만 120으로 변경한 규칙으로 포맷팅됩니다.

```bash
mkdir build
cd build
cmake ..
make clangformat
```
