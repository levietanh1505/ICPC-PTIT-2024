/*
    Mr X. có ba cửa hàng cùng bán thiết bị điện tử. Ông ấy đã gán ID cho mỗi dòng sản phẩm là một dãy 6 chữ số (có thể bắt đầu bởi các chữ số 0). Mỗi giao dịch bán hàng được lưu lại dưới dạng ID kèm theo số lượng. Sau đó được thống kê theo từng ngày.

Mr X. rất muốn biết danh sách các mặt hàng đã bán được từ 20 đơn vị trở lên ở cả 3 cửa hàng trong ngày hôm qua.

Input

Dòng đầu ghi ba số 0 < n1, n2, n3 < 200 là số lượng các giao dịch trong ngày hôm qua tại từng cửa hàng.

Tiếp theo đó là một số dòng ghi lần lượt n1 + n2 + n3 giao dịch trong ngày hôm qua, mỗi giao dịch có ID và số lượng cách nhau một khoảng trống. Do thiết bị điện tử không hề rẻ nên giới hạn cho các giao dịch đơn lẻ là không quá 100 đơn vị.

Output

Ghi ra  số m là số lượng các mặt hàng đã bán được từ 20 đơn vị trở lên trong cả ba cửa hàng.

Sau đó lần lượt là m giá trị ID của các mặt hàng thỏa mãn, đượt liệt kê theo thứ tự xuất hiện trong input.
 */


//ordermap
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    unordered_map<string, int> store1, store2, store3;
    string id;
    int num;

    vector<string> a;

    for(int i = 0; i < n1; ++i){
        cin >> id >> num;
        store1[id] += num;
        a.push_back(id);
    }
    
    for(int i = 0; i < n2; ++i){
        cin >> id >> num;
        store2[id] += num;
    }


    for(int i = 0; i < n3; ++i){
        cin >> id >> num;
        store3[id] += num;
    }

    vector<string> res;

    for(const auto& entry : store1){
        string id = entry.first;
        if(store2.find(id) != store2.end() && store3.find(id) != store3.end() && 
            entry.second >= 20 && store2[id] >= 20 && store3[id] >= 20)
            res.push_back(id);
    }
    
    sort(res.begin(), res.end(), [&a](const string &x, const string &y){
        auto itx = find(a.begin(), a.end(), x);
        auto ity = find(a.begin(), a.end(), y);

        return (itx < ity);
    });

    cout << res.size() << " ";
    for(const auto& id : res)
        cout << id << " ";
    
    return 0;
}