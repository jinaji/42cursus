CD = cd ./srcs/
DOCKER_COMPOSE = docker compose

all: up

up: 
	$(CD) && $(DOCKER_COMPOSE) up --build -d 

ps:
	$(CD) && $(DOCKER_COMPOSE) ps

stop:
	$(CD) && $(DOCKER_COMPOSE) stop

down:
	$(CD) && $(DOCKER_COMPOSE) down

clean:
	$(DOCKER_COMPOSE) --file ./srcs/docker-compose.yml down --rmi all --volumes

fclean: clean
	docker system prune -af
	@sudo rm -rf /home/jinkim2/data/mariadb/*
	@sudo rm -rf /home/jinkim2/data/nginx/*
	@sudo rm -rf /home/jinkim2/data/wordpress/*

md:
	docker logs --tail 50 --follow mariadb

ng:
	docker logs --tail 50 --follow nginx

wp:
	docker logs --tail 50 --follow wordpress

re: fclean up