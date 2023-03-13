# 42Seoul-philosophers
## 개요
- 이 과제를 성공적으로 수행하기 위해 알아야 할 사항은 아래와 같다:
  - 한 명 이상의 철학자가 둥근 테이블에 앉아있다.
  - 테이블 중앙에는 스파게티가 담겨져있는 큰 그릇이 있다.
  - 철학자들은 번갈아가며 먹고(eat), 생각하고(think), 잔다(sleep).
  - 먹는 동안에는, 생각하거나 자지 않는다.
  - 생각하는 동안에는, 먹거나 자지 않는다.
  - 잠을 자는 동안에는, 먹거나 생각하지 않는다.
  - 테이블에는 철학자 수 만큼의 포크들이 놓여져있다.
  - 포크 하나로 스파게티를 먹는 것은 매우 불편하기 때문에, 철학자는 오른쪽 포크와 왼쪽 포크를 각각 손에 들고 먹는다.
  - 철학자가 먹는 것을 마치면, 포크를 테이블에 내려놓고, 잠을 잔다.
  - 잠을 자고 나면, 생각을 한다.
  - 이러한 시뮬레이션은 철학자가 굶어 죽으면 중지된다.
  - 모든 철학자들은 음식을 먹는 것이 필요하며, 절대 굶으면 안된다.
  - 철학자들은 다른 철학자들과 얘기를 하지 않는다.
  - 철학자들은 다른 철학자가 죽었는지 모른다.
  - 철학자는 죽지 않아야 한다.

## 규칙
- 전역 변수 사용이 금지된다.
- 프로그램은 아래와 같이 인자들을 받아야 한다:
  - ```number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]```
  - number_of_philosophers : 철학자와 포크의 개수.
  - time_to_die (in milliseconds) : 철학자가 마지막 식사 또는 시뮬레이션 시작부터 time_to_die 밀리초 동안 식사를 못하면 죽는다.
  - time_to_eat (in milliseconds) : 철학자가 식사하는 데 필요한 시간이며, 이 시간동안 철학자는 두 개의 포크를 들고 있는다.
  - time_to_sleep (in milliseconds) : 철학자가 자는 시간.
  - number_of_times_each_philosopher_must_eat (optional argument) : 시뮬레이션을 중지하기 위해 모든 철학자가 음식을 먹어야하는 최소한의 횟수. 이 인자는 선택적으로 사용할 수 있으며, 사용하지 않을 경우 철학자가 죽으면 시뮬레이션이 종료된다.
- 각 철학자는 1 부터 number_of_philosophers 까지의 숫자를 가진다.
- 1번 철학자는 number_of_philosophers번 철학자 옆에 않는다.
- 다른 모든 N번 철학자는 N - 1, N + 1번 철학자 사이에 않는다.
- 프로그램이 나타내는 것은 다음과 같다:
  - 철학자의 모든 상태 변화를 아래와 같은 형식으로 나타내야 한다:
    - timestamp_in_ms X has taken a fork
    - timestamp_in_ms X is eating
    - timestamp_in_ms X is sleeping
    - timestamp_in_ms X is thinking
    - timestamp_in_ms X died
  - timestamp_in_ms 부분을 milliseconds 단위의 현재 [timestamp](https://ko.wikipedia.org/wiki/%ED%83%80%EC%9E%84%EC%8A%A4%ED%83%AC%ED%94%84#:~:text=%ED%83%80%EC%9E%84%EC%8A%A4%ED%83%AC%ED%94%84(%EC%98%81%EC%96%B4%3A%20timestamp),%EC%9E%88%EB%8A%94%20%ED%98%95%EC%8B%9D%EC%9C%BC%EB%A1%9C%20%ED%91%9C%ED%98%84%EB%90%9C%EB%8B%A4.)로 바꾸고, X 부분을 철학자 번호로 바꿔서 나타내면 된다.
  - 표시된 상태 메세지는 다른 메세지와 섞이면 안된다.
  - 철학자의 죽음을 알리는 메세지는, 실제 철학자가 죽은지 10ms 이내에 표시되어야 한다.
  - 프로그램은 무조건 어떠한 [data races](https://en.wikipedia.org/wiki/Race_condition)라도 있으면 안된다.
  
## Mandatory
- 프로그램명 = philo
- 제출 폴더명 = philo/
- 제출 파일 = Makefile, *.h, *.c
- 프로그램 인자 : ```number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]```
- 허용 함수 : ```memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock```
- 각 철학자는 thread 이어야 한다.
- 철학자 사이에 포크가 한 개씩 존재한다.
- 철학자가 한 명일 경우, 포크는 한 개 존재한다.
- 다수의 철학자가 있는 경우, 포크는 철학자의 왼쪽, 오른쪽에 존재한다.
- 철학자들이 포크의 중복 사용을 방지하기 위해 mutex를 사용하여 포크 상태를 보호해야 한다.
  
## Bonus
- 프로그램명 = philo_bonus
- 제출 폴더명 = philo_bonus/
- 제출 파일 = Makefile, *.h, *.c
- 프로그램 인자 : ```number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]```
- 허용 함수 : ```memset, printf, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink```
- 모든 포크는 테이블의 중앙에 놓여져있다.
- 포크의 상태는 없지만, 사용 가능한 포크의 개수가 semaphore로 표시된다.
- 각 철학자는 process 이어야 하지만, main process는 철학자이면 안된다.
