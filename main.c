#include<curl/curl.h>
#include<stdio.h>

size_t writer(char*, size_t, size_t, void*);

int main() {
  CURL *curl = curl_easy_init();
  CURLcode e;
  
  if(!curl) {
    fprintf(stderr,"Curl not initialized");
    return -1;
  }
  
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write);
  curl_easy_setopt(curl, CURLOPT_URL, *url);
  e = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  
  if(e != CURLE_OK){
    fprintf(stderr, "Could not perform operation");
    return 1;
  }
  return 0;
}


size_t writer(char* res, size_t s, size_t as, void* data) {
  return as;
}
