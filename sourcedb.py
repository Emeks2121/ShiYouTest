import time
from selenium import webdriver
from lxml import etree


#实例化一个浏览器对象（传入浏览器的驱动器）
bro=webdriver.Chrome()
#让浏览器发起一个指定url对应请求
url_pattern = "https://www.boc.cn/sourcedb/whpj/index{}.html"
all_list=""
for page_number in range(0,10):
        url=url_pattern.format("" if page_number == 1 else "_" + str(page_number))
        bro.get(url)
        #page_source获取浏览器当前页面的页面源码数据
        page_text=bro.page_source

        #利用Xpath解析代码
        tree=etree.HTML(page_text)
        tr_list = tree.xpath('//div[@class="publish"]/div[2]//tbody/tr')

        # 遍历每一行，并提取
        fp=open('result.txt','w',encoding='utf-8')
        for tr in tr_list[2:]:
                msg_list= tr.xpath('./td/text()')
                for msg in msg_list:
                        all_list+=msg+" "
                all_list+="\n"

print(all_list)
fp.write(all_list)
