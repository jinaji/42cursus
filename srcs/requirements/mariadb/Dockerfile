FROM debian:buster

EXPOSE 3306

COPY ./tools/setting.sh /setting.sh

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y mariadb-server mariadb-client dumb-init && \
    mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chmod +x setting.sh && \
    rm -f /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./conf/jinkim2_50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["sh", "-c", "./setting.sh"]