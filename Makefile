.PHONY: clean All

All:
	@echo "----------Building project:[ FindFirstRep - Debug ]----------"
	@cd "FindFirstRep" && "$(MAKE)" -f  "FindFirstRep.mk"
clean:
	@echo "----------Cleaning project:[ FindFirstRep - Debug ]----------"
	@cd "FindFirstRep" && "$(MAKE)" -f  "FindFirstRep.mk" clean
