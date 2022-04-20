#include <grpcpp/grpcpp.h>
#include <time.h>

#include "WifsClient.h"
#include "wifs.grpc.pb.h"

static struct options {
    WifsClient* wifsclient;
    int show_help;
} options;


int init() {
    options.wifsclient = new WifsClient(grpc::CreateChannel(ip_server_wifs[0], grpc::InsecureChannelCredentials()));
}

int do_get(int key, char* val) {
 
    int rc = options.wifsclient->wifs_GET(key, val);

    return 0;  
}

int do_put(int key, char* val) {

    int rc = options.wifsclient->wifs_PUT(key, val);
  
    return 0;
}

