.PHONY: clean All

All:
	@echo "----------Building project:[ Inheritance1 - Debug ]----------"
	@cd "Inheritance1" && "$(MAKE)" -f  "Inheritance1.mk"
clean:
	@echo "----------Cleaning project:[ Inheritance1 - Debug ]----------"
	@cd "Inheritance1" && "$(MAKE)" -f  "Inheritance1.mk" clean
