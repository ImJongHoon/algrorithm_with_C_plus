008. 처음 떠올린 생각: postfix, prefix -> stack. 코드 의도는 맞음.
강좌에서 소개한 방식: 괄호 알고리즘에 따른 for문과 break 방식.

009. 처음 떠올린 생각: 제한시간 1초가 달려있는거 보니 단순히 반복문으로 50000 자연수의 모든 약수를 출력하는 건 어려울거라고 생각함.
약수의 약수로 조합을 해서 약수의 갯수를 구하는 수식이 있는가? (배낭문제처럼 이전 약수를 저장했다가 사용할 수 있는가?)
강좌에서 소개한 방식: n^2의 시간복잡도로는 1초안에 풀 수 없는게 맞음.
n개의 배열을 만들고 배수를 더해서 출력하는 방식으로 약수 구하기.

-> 방향성 자체는 맞음. 방식을 못 떠올렸을 뿐.
항상 기억할 점은, 시간을 줄이고자 하면 다른 자원을 더 써서 해결하는 경우가 많다. 그리고 그것이 메모리인 경우가 많다.

010. 각 자연수의 자리수 합 - 입력한 자연수 각자가 숫자로 쪼개서 덧셈. 어렵지 않은 알고리즘이고 함수를 쪼개서 쓰는 방식을 이야기하기 위해서 준비된 문제인듯함.

%연산자는 %10으로 1의자리수를 가져올 수 있고, 10씩 나눠서 일의자리 수를 앞당길 수 있음을 기억하기.

011. (첫인상)
이중 반복문(for이랑 while) : %로 자리수를 줄여서 0이 나올때까지 count
또는
100000까지 if문으로 입력 숫자가 n이상이면 (1 * 9) + (2 * 90) ... 하고 input 값에서 앞의 숫자들을 빼고 계산ㄴ

012. (첫인상)
얘는 이중 반복문으로 했을 때 좀 오래걸릴 것 같다. 그렇다고 일일히 다 하는 건 좀 아님.
일단 이중 반복문밖에 안 떠오름
아니면 반복문 하나에 if문인데 거꾸로 써나가서 몇~몇 사이는 n씩 오르도록 설계

013. (첫인상)
0부터 9까지 배열을 만들고
100자리 자연수 입력을 어케받음?
입력 받고 나서는 100자리부터 점점 줄여가면서 %를 하고, 0이 안 나온 시점부터 카운팅을 시작한다.(if문으로 체크)
