#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//directory와 file을 관리하는 구조체 counter_t
typedef struct counter {
    size_t dirs;
    size_t files;
} counter_t;

//현재 open한 directory의 정보를 관리하는 구조체 entry_t
typedef struct entry {
    char *name; //현재 디렉토리의 이름을 저장
    int is_dir; //현재 디렉토리의 타입을 저장
    struct entry *next; //다음 디렉토리의 정보를 저장
} entry_t;

//function that implements tree structure
//parameter: directory, prefix, counter(file과 dir의 수를 관리)
int tree(const char *directory, const char *prefix, counter_t *counter) {
    entry_t *head = NULL, *current, *iter;
    size_t size = 0, index;

    struct dirent *file_dirent; //directory의 정보를 관리하는 구조체
    DIR *dir_handle; //directory stream(디렉토리의 파일을 조작하기 위한 포인터 Dir)

    char *full_path, *segment, *pointer, *next_prefix;
    
    //open directory 
    dir_handle = opendir(directory); 
    if (!dir_handle) {
        fprintf(stderr, "Cannot open directory \"%s\"\n", directory);
        return -1;
    }
    
    counter->dirs++;
    
    //read a directory that opens now if it is not NULL
    while ((file_dirent = readdir(dir_handle)) != NULL) {
        if (file_dirent->d_name[0] == '.') //최상위 디렉토리일 경우 continue
        {
            continue;
        }

        current = malloc(sizeof(entry_t)); //현재 디렉토리의 정보를 메모리에 할당
        current->name = strcpy(malloc(strlen(file_dirent->d_name) + 1),
                               file_dirent->d_name); //디렉토리의 정보를 current에 저장
        current->is_dir = file_dirent->d_type == DT_DIR;
        current->next = NULL;
        
        //head entry가 NULL 상태면 current entry를 head entry에 대입
        if (head == NULL) {
            head = current;
        } 
        //head의 이름이 current의 이름보다 더 클 경우(이름 순으로 정렬) 현재 entry의 next에 head를 대입하고 head entry에 current entry값 저장
        else if (strcmp(current->name, head->name) < 0) {
            current->next = head;
            head = current;
        }
        //정렬된 경우 
        else {
            //iter의 entry에 head의 entry를 대입하고 iter의 next값이 NULL이 아니고 cur name이 head name보다 클 때까지 반복, iter의 값이 head의 next값으로 바뀜
            for (iter = head;
                 iter->next && strcmp(current->name, iter->next->name) > 0;
                 iter = iter->next)
                ;
            
            current->next = iter->next; //cur의 next에 iter의 next를 대입
            iter->next = current; //iter의 next에 current 값을 대입
            //iter의 next를 제외한 entry는 cur로 대입하고 next는 유지 
        }

        size++; //read한 directory의 수
    }

    closedir(dir_handle);
    if (!head) {
        return 0;
    }
    
    //트리 구조의 모양
    for (index = 0; index < size; index++) {
        if (index == size - 1) {
            pointer = "└── ";
            segment = "    ";
        } else {
            pointer = "├── ";
            segment = "│   ";
        }
        
        //트리 구조 출력
        printf("%s%s%s\n", prefix, pointer, head->name);
        
        //디렉토리일 경우 실행
        if (head->is_dir) {
            full_path = malloc(strlen(directory) + strlen(head->name) + 2); //디렉토리의 경로와 이름의 수를 메모리에 할당
            sprintf(full_path, "%s/%s", directory, head->name); //디렉토리의 경로와 이름을 저장

            next_prefix = malloc(strlen(prefix) + strlen(segment) + 1); //prefix와 segment의 수를 메모리에 할당
            sprintf(next_prefix, "%s%s", prefix, segment); //next_prefix에 prefix와 segment의 값을 저장(들여쓰기)
            
            //재귀함수로 tree 모양 
            tree(full_path, next_prefix, counter);
            free(full_path);
            free(next_prefix);
        } else {
            counter->files++;
        }
        
        //current entry를 head enrty에 대입하고 head는 head의 next에 대입
        current = head;
        head = head->next;

        free(current->name);
        free(current);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char *directory = argc > 1 ? argv[1] : "."; //1보다 크면 argv[1]의 값을 아니면 .을 directory 값에 저장 (directory 값은 open할 디렉토리의 경로를 의미)
    printf("%s\n", directory);

    counter_t counter = {0, 0};
    tree(directory, "", &counter);

    printf("\n%zu directories, %zu files\n",
           counter.dirs ? counter.dirs - 1 : 0, counter.files);
    return 0;
}
