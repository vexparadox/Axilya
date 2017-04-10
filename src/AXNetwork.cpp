#include "headers/AXNetwork.hpp"
#include <iostream>

bool AXNetwork::hasInit = false;

AXNetwork::~AXNetwork(){
	curl_global_cleanup();
}

void AXNetwork::init(){
	if(hasInit){
		return;
	}
	curl_global_init(CURL_GLOBAL_ALL);
	hasInit = true;
}

size_t AXNetwork::eatOutput(void *ptr, size_t size, size_t nmemb, void *data){
	return size*nmemb;
}

bool AXNetwork::POSTRequestSimple(const std::string& url, const std::vector<AXNetworkPair>& pair, bool shouldPrint){
	CURL* curl = curl_easy_init();
	CURLcode res;
	if(curl) {
	    std::string post;
	    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	    if(pair.size() > 0){
		    //construct the first kvp without a &
		    post.append(pair[0].first);
		    post.append("=");
		    post.append(pair[0].second);
		    //for the rest build &first=second etc.
		    for(int i = 1; i < pair.size(); i++){
		    	post.append("&");
			    post.append(pair[i].first);
		    	post.append("=");
		    	post.append(pair[i].second);
		    }
		    //set the post fields
		    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post.c_str());
		}
		if(!shouldPrint){
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, AXNetwork::eatOutput);
		}
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36");
		//send
	    res = curl_easy_perform(curl);
	    //if it broke
	    if(res != CURLE_OK){
	      AXLog::log("POSTRequestSimple failed to send", curl_easy_strerror(res), AX_LOG_ERROR);
	      curl_easy_cleanup(curl);
	      return false;
	    }
	    curl_easy_cleanup(curl);
	    std::cout << std::endl;
	    return true;
    }else{
    	return false;
    }
}

void AXNetwork::MTPOSTRequestSimple(const std::string& url, const std::vector<AXNetworkPair>& pair, bool shouldPrint){
	std::thread t(AXNetwork::POSTRequestSimple, url, pair, shouldPrint);
	t.detach();
}

bool AXNetwork::POSTRequest(const std::string& url, const std::vector<AXNetworkPair>& pair, const std::vector<AXNetworkPair>& headers, AXNetworkCallback callback){
	CURL* curl = curl_easy_init();
	CURLcode res;
	if(curl) {
	    std::string post;
	    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	    if(pair.size() > 0){
		    //construct the first kvp without a &
		    post.append(pair[0].first);
		    post.append("=");
		    post.append(pair[0].second);
		    //for the rest build &first=second etc.
		    for(int i = 1; i < pair.size(); i++){
		    	post.append("&");
			    post.append(pair[i].first);
		    	post.append("=");
		    	post.append(pair[i].second);
		    }
		    //set the post fields
		    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post.c_str());
		}


		struct curl_slist *chunk = 0;
		for(int i = 0; i < headers.size(); i++){
			std::string temp;
			temp.append(headers[i].first);
			temp.append(": ");
			temp.append(headers[i].second);
			chunk = curl_slist_append(chunk, temp.c_str());
		}

		if(callback){
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		}else{
		    AXLog::log("Invalid callback", "AXNetwork::POSTRequest", AX_LOG_ERROR);
		    curl_easy_cleanup(curl);
			return false;
		}
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36");
		if(chunk){
			res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		}
		//send
	    res = curl_easy_perform(curl);
	    //if it broke
	    if(res != CURLE_OK){
	      	AXLog::log("POSTRequestSimple failed to send", curl_easy_strerror(res), AX_LOG_ERROR);
	      	curl_easy_cleanup(curl);
	      	return false;
	    }
	    curl_easy_cleanup(curl);
	    return true;
    }else{
    	return false;
    }
}

void AXNetwork::MTPOSTRequest(const std::string& url, const std::vector<AXNetworkPair>& pair, const std::vector<AXNetworkPair>& headers, AXNetworkCallback callback){
	std::thread t(AXNetwork::POSTRequest, url, pair, headers, callback);
	t.detach();
}