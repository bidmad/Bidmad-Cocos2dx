#!/bin/bash

# Prompt user for new versions
read -p "Enter new version for BidmadSDK: " BIDMADSDK_VERSION
read -p "Enter new version for OpenBiddingHelper: " OPENBIDDINGHELPER_VERSION
read -p "Enter new version for BidmadAdapterDynamic: " BIDMADADAPTERDYNAMIC_VERSION

# List of files to update
FILES=("proj.ios_mac/Podfile" "README-EN.md" "README.md")

# Update versions in files
for FILE in "${FILES[@]}"; do
    if [[ -f $FILE ]]; then
        sed -i.bak -E "s/(pod 'BidmadSDK', ')[^']+'/\1$BIDMADSDK_VERSION'/" "$FILE"
        sed -i.bak -E "s/(pod 'OpenBiddingHelper', ')[^']+'/\1$OPENBIDDINGHELPER_VERSION'/" "$FILE"
        sed -i.bak -E "s/(pod 'BidmadAdapterDynamic', ')[^']+'/\1$BIDMADADAPTERDYNAMIC_VERSION'/" "$FILE"
        
        # Remove backup files (optional)
        rm -f "$FILE.bak"
    else
        echo "Warning: $FILE does not exist."
    fi
done

echo "Versions updated successfully!"
