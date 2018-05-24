# -*- coding: utf-8-*-
import sys
import os
import re

def filter_tags(htmlstr):

    re_cdata=re.compile('//<!\[CDATA\[[^>]*//\]\]>',re.I) #匹配CDATA
    re_script=re.compile('<\s*script[^>]*>[^<]*<\s*/\s*script\s*>',re.I)#Script
    re_style=re.compile('<\s*style[^>]*>[^<]*<\s*/\s*style\s*>',re.I)#style
    re_br=re.compile('<br\s*?/?>')#处理换行
    re_h=re.compile('</?\w+[^>]*>')#HTML标签
    re_comment=re.compile('<!--[^>]*-->')#HTML注释
    s=re_cdata.sub('',htmlstr)#去掉CDATA
    s=re_script.sub('',s) #去掉SCRIPT
    s=re_style.sub('',s)#去掉style
    s=re_br.sub('\n',s)#将br转换为换行
    s=re_h.sub('',s) #去掉HTML 标签
    s=re_comment.sub('',s)#去掉HTML注释

    blank_line=re.compile('\n+')
    s=blank_line.sub('\n',s)
    s=replaceCharEntity(s)#替换实体
    return s


def replaceCharEntity(htmlstr):
    CHAR_ENTITIES={'nbsp':' ','160':' ',
                   'lt':'<','60':'<',
                   'gt':'>','62':'>',
                   'amp':'&','38':'&',
                   'quot':'"','34':'"',}

     re_charEntity=re.compile(r'&#?(?P<name>\w+);')
     sz=re_charEntity.search(htmlstr)
     while sz:
         entity=sz.group()#entity全称，如&gt;
         key=sz.group('name')#去除&;后entity,如&gt;为gt
         try:
                 htmlstr=re_charEntity.sub(CHAR_ENTITIES[key],htmlstr,1)
                 sz=re_charEntity.search(htmlstr)
         except KeyError:
                 htmlstr=re_charEntity.sub('',htmlstr,1)
                 sz=re_charEntity.search(htmlstr)
                 return htmlstr

def enum_dir(input_path, file_list):
    ls = os.listdir(input_path)
    for f in ls:
        fullpath = os.path.join(input_path, f)
        if os.path.isdir(fullpath):
            enum_dir(fullpath, file_list)
        else:
            if os.path.splitext(fullpath)[1] != '.html':
                continue
            file_list.append(fullpath)
    return

def replaceAllFile(input_path, output_path):
    if input_path[-1] != '/':
        input_path = input_path + '/'
        file_list = []
        enum_dir(input_path, file_list)
        for f in file_list:
            content = file(f).read()
            plain_content = filter_tags(content)
            output_file = os.path.join(output_path, f[len(input_path):])
            output_dir = os.path.dirname(output_file)
            if not os.path.exists(output_dir):
                os.makedirs(output_dir)
            file(output_file, 'w').write(plain_content)
            print 'file:' + output_file + ' done!'

if __name__=='__main__':
    if len(sys.argv) != 3:
        print "need arg 'input_path' and 'output_path' !"
    else:
        replaceAllFile(sys.argv[1], sys.argv[2])
