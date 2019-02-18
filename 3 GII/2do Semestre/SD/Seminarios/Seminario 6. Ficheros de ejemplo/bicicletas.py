# -*- coding: utf-8 -*-
import scrapy

def save_page(page_num, response):
    response.meta['page'] = page_num

def get_page(response):
    page_num = response.meta.get('page')

    if not page_num:
        page_num = 1

    return page_num

class BicicletasSpider(scrapy.Spider):
    name = "bicicletas"
    start_urls = ['http://www.milanuncios.com/bicicletas-en-cadiz/']
    limits_page = 2

    def parse(self, response):
        anuncios = response.css('div.aditem-detail')

        for anuncio in anuncios:
            title = anuncio.css('a.aditem-detail-title::text').extract_first()
            text = anuncio.css('div.tx::text').extract_first()
            price = anuncio.css('div.aditem-price::text').extract_first()
            yield {'title': title, 'text': text, 'price': price}

        page_num = get_page(response)

        next = response.xpath('//a[text()="Siguiente"]')

        if next is not None and page_num < self.limits_page:
            page_num += 1
            save_page(page_num, response)
            next_page = next.css('::attr(href)').extract_first()
            next_page = response.urljoin(next_page)
            yield scrapy.Request(next_page, callback=self.parse)

