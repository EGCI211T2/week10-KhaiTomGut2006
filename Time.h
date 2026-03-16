struct Time {
  int m, h, s;
};

void getTime(struct Time &t) {
    cin >> t.h >> t.m >> t.s;
}

struct Time subtract(struct Time t_end, struct Time t_start) {
    struct Time t3;
    int start_sec = t_start.h * 3600 + t_start.m * 60 + t_start.s;
    int end_sec = t_end.h * 3600 + t_end.m * 60 + t_end.s;
    int diff = end_sec - start_sec;
    
    // ถ้าติดลบ ให้บวก 24 ชั่วโมง (เพื่อคิดเป็นวันพรุ่งนี้)
    if (diff < 0) {
        diff += 24 * 3600;
    }
    
    t3.h = diff / 3600;
    t3.m = (diff % 3600) / 60;
    t3.s = diff % 60;
    
    return t3;
}

void display(struct Time t) {
    cout << setfill('0') << setw(2) << t.h << ":"
         << setfill('0') << setw(2) << t.m << ":"
         << setfill('0') << setw(2) << t.s << endl;
}