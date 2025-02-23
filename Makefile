.PHONY: clean All

All:
	@echo "----------Building project:[ PlatformCheck - Debug ]----------"
	@cd "PlatformCheck" && "$(MAKE)" -f  "PlatformCheck.mk"
clean:
	@echo "----------Cleaning project:[ PlatformCheck - Debug ]----------"
	@cd "PlatformCheck" && "$(MAKE)" -f  "PlatformCheck.mk" clean
