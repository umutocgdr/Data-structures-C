#include<stdio.h>

// fork kutupanesi
#include<unistd.h>


int main(){

    int pid; // fork tan alınan pid degeri buna aktarılcak

    pid = getpid();

    // suan parent proses teyız fakat fork la child proses olusur ve forktan donen sonuc childin prosesıdır
    printf("parent pid : %d  \n", pid);

    pid = fork(); // bundan sonra 2 proses olcak bi ana(parent) bı child

    if(pid > 0 ){
    // frok tan chldin pid sı gelir parent ın pidini almak ini getpid() fonk kullanılır
        printf("parent : %d , benim pid : %d \n",pid,getpid());

    }else if(pid == 0){
     // child proses ..... child kendi pidini bilmez 0 kabul eder getpid() fonk yla child ın pidi alınır
        printf("child : %d , benim pid : %d \n",pid,getpid());
    }else if(pid < 0){
        // yazdıgın koddahata varsa burası calısır
    }


}
