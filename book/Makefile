.PHONY: deploy

deploy:
	git worktree add /tmp/book gh-pages
	mdbook build
	rm -rf /tmp/book/*
	cp -rp build/* /tmp/book
	cd /tmp/book && \
	git update-ref -d refs/heads/gh-pages && \
	git add -A && \
	git commit -m "deployed on $(shell date) by $(USER)" && \
	git push --force origin gh-pages
	git worktree remove /tmp/book
	git branch -D gh-pages
