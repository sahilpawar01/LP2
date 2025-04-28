def stock_market_expert_system():
    print("📈 Welcome to the Stock Market Trading Expert System 📈")
    print("Please answer the following questions with 'yes' or 'no'.\n")

    price_up = input("Is the stock price rising? ").lower()
    high_volume = input("Is the trading volume higher than usual? ").lower()
    positive_news = input("Is there any positive news about the company? ").lower()
    market_bullish = input("Is the overall market trend bullish? ").lower()
    price_down = input("Is the stock price falling sharply? ").lower()
    negative_news = input("Is there any negative news about the company? ").lower()

    print("\n🧠 Trading Advice:")

    if price_up == "yes" and high_volume == "yes" and positive_news == "yes" and market_bullish == "yes":
        print("- Action: STRONG BUY 🛒")
        print("- Reason: Positive momentum and market support.")
    
    elif price_up == "yes" and (positive_news == "yes" or market_bullish == "yes"):
        print("- Action: BUY ✅")
        print("- Reason: Stock showing strength, supported by good news or market trend.")
    
    elif price_down == "yes" and negative_news == "yes":
        print("- Action: SELL 🚨")
        print("- Reason: Price dropping with negative sentiment. Better to exit.")
    
    elif price_down == "yes" and market_bullish == "no":
        print("- Action: SELL or HOLD ⚠️")
        print("- Reason: Market weak and stock falling. Assess risk tolerance.")
    
    else:
        print("- Action: HOLD 🤔")
        print("- Reason: No strong signals. Wait for clearer opportunity.")

    print("\n✅ Thank you for using the Stock Market Expert System! Trade wisely!")

# Run the system
stock_market_expert_system()
