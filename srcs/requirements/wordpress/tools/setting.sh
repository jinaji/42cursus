#!/bin/sh

wp-cli core download --allow-root
wp-cli config create --dbname=$MYSQL_DB --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$MYSQL_HOST --allow-root
wp-cli core install --url=$DOMAIN_NAME/wordpress --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
wp-cli user create $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --role=contributor --allow-root

exec /usr/sbin/php-fpm7.3 -F