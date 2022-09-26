int main(int argc, char* argv[]){
  for(int i=0; i<argc; ++i){
    {
      cout << "argc[" <<i<<"]은 "<<argv[i]<<"입니다.\n";
    }
    return 0;
  }
  
  //int argc - main() 함수에 전달되는 데이터의 개수
  //char* argv[] - main() 함수에 전달되는 실제적인 데이터로 char형 포인터 배열로 구성되어 있다. 첫 번째 문자열은 프로그램의 실행경로
