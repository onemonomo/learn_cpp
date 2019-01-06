# coding=utf8
# 从隔壁库拷贝而来
import sys
import os

def edit(file_path):
    if '.cpp' == file_path[-4:]:
        os.system('g++ -S '+file_path+' -o '+file_path[0:-4]+'.s')

def travel(abs_path):
    for sub_dir, sub_dir_of_subdir, files_in_sub_dir in os.walk(abs_path):
        for single_file in files_in_sub_dir:
            file_abs_path = os.path.join(sub_dir, single_file)
            edit(file_abs_path)
    
def main():
    for path in sys.argv[1:]:
        print "this is the path you want to edit: ",path
        travel(path)
    print "compile.py finish"
        
if __name__ == "__main__":
    main()