#include "util.h"

void write_file(const char *file_path, string msg)
{
    //组织文件名
    time_t now = time(nullptr);
    tm *now_time = localtime(&now);
    char file_name[FILE_SIZE] = {0};
    sprintf(file_name, "%4d-%2d-%2d_log.txt", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday);

    string file_str = file_path;
    file_str += "/";
    file_str += file_name;

    // 组织日志格式
    char input_str[INPUT_SIZE] = {0};
    memset(input_str, 0, INPUT_SIZE);
    sprintf(input_str, "%2d:%2d:%2d=> ", now_time->tm_hour, now_time->tm_min, now_time->tm_sec);
    msg.insert(0, input_str);
    msg += '\n';

    FILE *fp = fopen(file_str.c_str(), "a+");
    if (fp == nullptr)
    {
        cout << "can't open file: " << file_path << endl;
        return;
    }
    fputs(msg.c_str(), fp);
    fclose(fp);
}