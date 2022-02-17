# TODO (Khangaroo): Make this process a lot less hacky (no, export did not work)
# See MakefileNSO

.PHONY: all clean starlight send

S2VER ?= 100
S2VERSTR ?= 1.0.0
S2ROMTYPE ?= US
IP ?= 10.0.0.222 # Put Switch IP Here (for make send)
USER ?= crafty # Put username here (for make send)
PASS ?= boss # put password here (for make send)

PROJNAME ?= StarlightBase

all: starlight

starlight:
	$(MAKE) all -f MakefileNSO S2VER=$(S2VER) S2VERSTR=$(S2VERSTR)
	$(MAKE) starlight_patch_$(S2VER)/*.ips
	
	mkdir -p starlight_patch_$(S2VER)/atmosphere/exefs_patches/$(PROJNAME)/
	mkdir -p starlight_patch_$(S2VER)/atmosphere/contents/0100000000010000/exefs/
	
	mv starlight_patch_$(S2VER)/3CA12DFAAF9C82DA064D1698DF79CDA1.ips starlight_patch_$(S2VER)/atmosphere/exefs_patches/$(PROJNAME)/3CA12DFAAF9C82DA064D1698DF79CDA1.ips
	mv $(shell basename $(CURDIR))$(S2VER).elf starlight_patch_$(S2VER)/subsdk1.elf
	mv $(shell basename $(CURDIR))$(S2VER).nso starlight_patch_$(S2VER)/atmosphere/contents/0100000000010000/exefs/subsdk1

starlight_patch_$(S2VER)/*.ips: patches/*.slpatch patches/configs/$(S2VER).config patches/maps/$(S2VER)/*.map \
								build$(S2VER)/$(shell basename $(CURDIR))$(S2VER).map scripts/genPatch.py
	@rm -f starlight_patch_$(S2VER)/*.ips
	python3 scripts/genPatch.py $(S2VER)

# NOTE: Make sure you configure sendPatch.py to use your login for ftp servers!
send: all
	python3.8 scripts/sendPatch.py $(IP) $(PROJNAME) $(USER) $(PASS)

clean:
	$(MAKE) clean -f MakefileNSO
	@rm -fr starlight_patch_*