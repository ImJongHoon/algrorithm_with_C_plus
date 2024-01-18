#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct info {
    string category;
    int songNum;
    int views;
};

//내림차순
int cmp_by_category(pair<string, int>&x, pair<string, int>&y) {

    return x.second > y.second;
}

//내림차순
int cmp_by_views(info x, info y) {
    return x.views > y.views;
}

//1. 수록할 장르 순서 정하기
//2. 장르당 수록할 곡 순서 정하기(조회수 같으면 낮은 고유번호)
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    vector<info> songData;

    unordered_map<string, int> rank_map;

    for (int i = 0; i < genres.size(); i++) {
        //음악 데이터 생성
        info music;
        music.category = genres[i];
        music.songNum = i;
        music.views = plays[i];
        songData.push_back(music);

        if (rank_map.find(genres[i]) == rank_map.end()) {
            rank_map[genres[i]] = plays[i];
        }
        else {
            rank_map[genres[i]] = rank_map[genres[i]] + plays[i];
        }
    }

    vector<pair<string, int>> map2vec(rank_map.begin(), rank_map.end());
    sort(map2vec.begin(), map2vec.end(), cmp_by_category);
    sort(songData.begin(), songData.end(), cmp_by_views);
    
    int cnt;

    for (int y = 0; y < map2vec.size(); y++) {
        cnt = 0;
        for (int x = 0; x < songData.size(); x++) {
            if (map2vec[y].first == songData[x].category) {
                answer.push_back(songData[x].songNum);
                cnt++;
            }
            if (cnt == 2) {
                break;
            }
        }
    }

    return answer;
}

int main() {


    return 0;
}