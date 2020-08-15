vector<int> arr{1, 2};

int getElementAt(int idx) {
    if (idx < arr.size()) return arr[idx];
    return -1;
}
bool doesElementExist(int e) {
    int l = 0;
    int r = 1;
    while (l <= r) {
        int rEle = getElementAt(r);
        if (rEle == -1 || rEle >= e) {
            int mid = l + (r - l) / 2;
            int midEle = getElementAt(mid);
            if (midEle == -1) r = mid - 1;
            else if (midEle == e) return true;
            else if (midEle > e) r = mid - 1;
            else l = mid + 1;
        } else {
            r *= 2;
        }
    }
    return false;
}

int main() {
    if (doesElementExist(2)) cout << "true" << endl;
    else cout << "false" << endl;
}
