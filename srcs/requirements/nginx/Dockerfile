FROM debian:buster

EXPOSE 443

RUN apt-get update \
    && apt-get -y upgrade \
    && apt-get -y install nginx dumb-init openssl \
    && mkdir -p /etc/nginx/tls \
    && openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gon/CN=jinkim2.42.fr" -out /etc/nginx/tls/jinkim2.42.fr.crt -keyout /etc/nginx/tls/jinkim2.42.fr.key

COPY ./conf/jinkim2_default.conf /etc/nginx/conf.d/default.conf

CMD ["nginx", "-g", "daemon off;"]

ENTRYPOINT ["/usr/bin/dumb-init", "--"]