# -*- coding: utf-8 -*-
# @Time : 2022-10-18
# @Author : Mculover666
# @File : get_netease_music.py
# @Version: v1.0

import requests
import json
import wget
import os

url = 'http://www.mculover666.cn:3000'
list_id = '7694329187'
user_id = '413751179'
path = "music/"

headers = {
            'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 ' \
                            '(KHTML, like Gecko) Chrome/92.0.4515.159 Safari/537.36'
}

def get_music_url(id):
    str=''
    url_req = url + "/song/url";
    params = {
        'id': id
    }
    response = requests.get(url_req, headers=headers, params=params)
    print(response.text)
    d = json.loads(response.text)
    print(type(d))
    l = d['data']
    i = l[0]
    str = i['url']
    print(str)
    return str

"""
    "songs":[
        {
            "name":"独角戏",
            "id":307525,
            "pst":0,
            "t":0,
            "ar":[{
                    "id":9943,
                    "name":"许茹芸",
                    "tns":[],
                    "alias":[]
                }],
            "alia":["中视黄金剧场《真爱一世情》插曲"],
            "pop":100,
            "st":0,
            "rt":"600902000005167735",
            "fee":8,
            "v":421,
            "crbt":null,
            "cf":"",
            "al":{
                "id":30534,
                "name":"如果云知道",
                "picUrl":"https://p1.music.126.net/UsuyJt2QTcwXSeX9RjVc0g==/109951166782958283.jpg",
                "tns":[],
                "pic_str":"109951166782958283",
                "pic":109951166782958290
                },
            "dt":277293,
            "h":{
                "br":320000,
                "fid":0,
                "size":11094769,
                "vd":12740,
                "sr":44100
                },
            "m":{
                "br":192000,
                "fid":0,
                "size":6656879,
                "vd":12740,
                "sr":44100
                },
            "l":{
                "br":128000,
                "fid":0,
                "size":4437933,
                "vd":12740,
                "sr":44100
                },
            "sq":{
                "br":825384,
                "fid":0,
                "size":28609248,
                "vd":12740,
                "sr":44100
            },
            "hr":null,
            "a":null,
            "cd":"1",
            "no":6,
            "rtUrl":null,
            "ftype":0,
            "rtUrls":[],
            "djId":0,
            "copyright":1,
            "s_id":0,
            "mark":8192,
            "originCoverType":1,
            "originSongSimpleData":null,
            "tagPicList":null,
            "resourceState":true,
            "version":421,
            "songJumpInfo":null,
            "entertainmentTags":null,
            "awardTags":null,
            "single":0,
            "noCopyrightRcmd":null,"rtype":0,"rurl":null,"mst":9,"cp":7003,"mv":0,"publishTime":820425600000}],
            "privileges":[{"id":307525,"fee":8,"payed":0,"st":0,"pl":128000,"dl":0,"sp":7,"cp":1,"subp":1,"cs":false,"maxbr":999000,"fl":128000,"toast":false,"flag":260,"preSell":false,"playMaxbr":999000,"downloadMaxbr":999000,"maxBrLevel":"lossless","playMaxBrLevel":"lossless","downloadMaxBrLevel":"lossless","plLevel":"standard","dlLevel":"none","flLevel":"standard","rscl":null,"freeTrialPrivilege":{"resConsumable":false,"userConsumable":false,"listenType":null},"chargeInfoList":[{"rate":128000,"chargeUrl":null,"chargeMessage":null,"chargeType":0},{"rate":192000,"chargeUrl":null,"chargeMessage":null,"chargeType":1},{"rate":320000,"chargeUrl":null,"chargeMessage":null,"chargeType":1},{"rate":999000,"chargeUrl":null,"chargeMessage":null,"chargeType":1}]}],
            "code":200
        }
"""

def get_music_list():
    music_list = list()
    url_req = url + "/playlist/track/all";
    params = {
        'id': list_id,
        'userid': user_id,
        'limit': 10,
        'offset': 0
    }
    response = requests.get(url_req, headers=headers, params=params)

    d = json.loads(response.text)
    print(type(d))
    l = d['songs']
    print(l)
    print(type(l))
    for i in l:
        music_dict = {"name": '', "id": 0, 'singer': '', 'pic_url': '', 'song_url': ''}
        print(i['name'])
        print(i['id'])
        music_dict['name'] = i['name']
        music_dict['id'] = i['id']
        signer=''
        pic_str=''
        ar = i['ar']
        for j in ar:
            signer=j['name']
        print(signer)
        music_dict['singer'] = signer
        al = i['al']
        pic_str=al['picUrl']
        print(pic_str)
        music_dict['pic_url'] = pic_str
        song_url = get_music_url(music_dict['id'])
        music_dict['song_url'] = song_url

        music_list.append(music_dict)
    
    return music_list

def get_music_file(music_list):
    print("find " + str(len(music_list)) + " songs!")
    if (os.path.exists(path) != True):
        os.mkdir(path)
    for i in music_list:
        url = i['song_url']
        print("--->" + url)
        mp3_filename = path + i['name'] + '-' + i['singer'] + '.mp3'
        if (os.path.exists(mp3_filename) != True):
            wget.download(url, mp3_filename)
        
        pic_url = i['pic_url']
        pic_filename = path + i['name'] + '-' + i['singer'] + '.jpg'
        if (os.path.exists(pic_filename) != True):
            wget.download(pic_url, pic_filename)

if __name__ == "__main__":
    music_list = get_music_list()
    get_music_file(music_list)
