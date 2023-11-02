FROM debian:buster

EXPOSE 9000

COPY ./tools/setting.sh /setting.sh

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y curl mariadb-client php7.3-fpm php-mysql dumb-init && \
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin && \
    ln -sf /usr/local/bin/wp-cli.phar /usr/local/bin/wp-cli && \
    mkdir -p /var/www/html/wordpress /run/php && \
    usermod -G www-data -a www-data && \
    chown -R www-data:www-data /var/www/ && \
    chmod +x setting.sh

WORKDIR /var/www/html/wordpress

COPY ./conf/jinkim2_www.conf /etc/php/7.3/fpm/pool.d/www.conf

CMD ["sh", "/setting.sh"]

ENTRYPOINT ["/usr/bin/dumb-init", "--"]