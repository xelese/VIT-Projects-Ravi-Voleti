import scrapy
from scrapy import Selector
from scrapy.selector import HtmlXPathSelector
from scrapy.spider import BaseSpider
import html2text
import lxml.etree
import lxml.html

class ReviewSpider(scrapy.Spider):
    name = "Movie1"

    def start_requests(self):
        urls = [ 'http://www.imdb.com/title/tt0167260/reviews?start=%d' % i for i in xrange(0,100,10)]
        for url in urls:
            yield scrapy.Request(url=url, callback=self.parse)
    def parse(self, response):
	root = lxml.html.fromstring(response.body)
	for p in root.xpath("//body//p"):
           fi=open('Review1.txt','a')
           fi.write(lxml.html.tostring(p, method="text"))
	   fi.close()

