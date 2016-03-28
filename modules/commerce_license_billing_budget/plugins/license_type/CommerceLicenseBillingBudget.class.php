<?php

/**
 * Billing Budget license type.
 */
class CommerceLicenseBillingBudget extends CommerceLicenseBase implements CommerceLicenseBillingUsageInterface {

  /**
   * Implements CommerceLicenseInterface::isConfigurable().
   */
  public function isConfigurable() {
    return FALSE;
  }
  
  /**
   * Implements CommerceLicenseBillingUsageInterface::usageGroups().
   */
  public function usageGroups() {
    // Prepare the products.
    $products = array(
      'compt_soc' => t('Accountant Budget for Society'),
      'compt_soc_for' => t('Accountant Budget for Society in formation'),
      'compt_asoc' => t('Accountant Budget for Association'),
      'compt_indep' => t('Accountant Budget for Independent'),
      'compt_indep_comp' => t('Accountant Budget for Complementary Independent'),
      'compt_indep_plan' => t('Accountant Budget for New Independent'),
      'photo_birthday' => t('Photographer Budget for Birthday'),
      'photo_conference' => t('Photographer Budget for Conference'),
      'photo_corporate' => t('Photographer Budget for Corporate'),
      'photo_family' => t('Photographer Budget for Family'),
      'photo_other' => t('Photographer Budget for Other'),
      'photo_wedding' => t('Photographer Budget for Wedding'),
    );
    // Define the prices.
    $prices = array('0250', '0300', '0350', '0400', '0450', '0500', '0550', '0600', 
                    '0650', '0700', '0750', '0800', '0850', '0900', '0950', '1000',
                    '1250', '1500', '1750', '2000', 
                    '2250', '2500', '2750', '3000', 
                    '3250', '3500', '3750', '4000', 
                    '4250', '4500', '4750', '5000');
    $ug = array();
    foreach ($products as $key => $title) {
      foreach ($prices as $price) {
        $sku = $key .'_'. $price;
        $ug[$sku] = array(
          'title' => $title .' ['. $price .']',
          'type' => 'counter',
          'product' => $sku,
          'free_quantity' => 0,
          'immediate' => TRUE,
        );
      }
    }
    
    // Other products.
    $ug['general_credit_note'] = array(
      'title' => t('Credit Note'),
      'type' => 'counter',
      'product' => 'credit_note',
      'free_quantity' => 0,
      'immediate' => TRUE,
    );
    $ug['promo_code_premier'] = array(
      'title' => t('Promo Code'),
      'type' => 'counter',
      'product' => 'promo_premier',
      'free_quantity' => 0,
      'immediate' => TRUE,
    );
    return $ug;
    
    /*
    return array(
      // Society
      'accountant_budget_society' => array(
        'title' => t('Accountant Budget for Society'),
        'type' => 'counter',
        'product' => 'compt_soc',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_society_high' => array(
        'title' => t('Accountant Budget for Society High'),
        'type' => 'counter',
        'product' => 'compt_soc_high',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_society_low' => array(
        'title' => t('Accountant Budget for Society Low'),
        'type' => 'counter',
        'product' => 'compt_soc_low',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      // Society in formation
      'accountant_budget_nonexistent' => array(
        'title' => t('Accountant Budget for Society in formation'),
        'type' => 'counter',
        'product' => 'compt_soc_for',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_nonexistent_high' => array(
        'title' => t('Accountant Budget for Society in formation High'),
        'type' => 'counter',
        'product' => 'compt_soc_for_high',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_nonexistent_low' => array(
        'title' => t('Accountant Budget for Society in formation Low'),
        'type' => 'counter',
        'product' => 'compt_soc_for_low',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      // Association
      'accountant_budget_association' => array(
        'title' => t('Accountant Budget for Association'),
        'type' => 'counter',
        'product' => 'compt_asoc',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_association_high' => array(
        'title' => t('Accountant Budget for Association High'),
        'type' => 'counter',
        'product' => 'compt_asoc_high',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_association_low' => array(
        'title' => t('Accountant Budget for Association Low'),
        'type' => 'counter',
        'product' => 'compt_asoc_low',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      // Independent
      'accountant_budget_independent' => array(
        'title' => t('Accountant Budget for Independent'),
        'type' => 'counter',
        'product' => 'compt_indep',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_independent_high' => array(
        'title' => t('Accountant Budget for Independent High'),
        'type' => 'counter',
        'product' => 'compt_indep_high',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_independent_low' => array(
        'title' => t('Accountant Budget for Independent Low'),
        'type' => 'counter',
        'product' => 'compt_indep_low',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      // Complementary Independent
      'accountant_budget_independent_comp' => array(
        'title' => t('Accountant Budget for Complementary Independent'),
        'type' => 'counter',
        'product' => 'compt_indep_comp',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_independent_comp_high' => array(
        'title' => t('Accountant Budget for Complementary Independent High'),
        'type' => 'counter',
        'product' => 'compt_indep_comp_high',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_independent_comp_low' => array(
        'title' => t('Accountant Budget for Complementary Independent Low'),
        'type' => 'counter',
        'product' => 'compt_indep_comp_low',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      // New Independent
      'accountant_budget_independent_plan' => array(
        'title' => t('Accountant Budget for New Independent'),
        'type' => 'counter',
        'product' => 'compt_indep_plan',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_independent_plan_high' => array(
        'title' => t('Accountant Budget for New Independent High'),
        'type' => 'counter',
        'product' => 'compt_indep_plan_high',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'accountant_budget_independent_plan_low' => array(
        'title' => t('Accountant Budget for New Independent Low'),
        'type' => 'counter',
        'product' => 'compt_indep_plan_low',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      // Others
      'general_credit_note' => array(
        'title' => t('Credit Note'),
        'type' => 'counter',
        'product' => 'credit_note',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
      'promo_code_premier' => array(
        'title' => t('Promo Code'),
        'type' => 'counter',
        'product' => 'promo_premier',
        'free_quantity' => 0,
        'immediate' => TRUE,
      ),
    );*/
  }

  /**
   * Implements CommerceLicenseBillingUsageInterface::usageDetails().
   */
  public function usageDetails() {
    $accountant_budget_usage = commerce_license_billing_current_usage($this, 'accountant_budget');

    $details = t('Bla bla Accountant Budget: @accountant_budget', array('@accountant_budget' => $accountant_budget_usage));
    return $details;
  }

  /**
   * Implements CommerceLicenseInterface::checkoutCompletionMessage().
   */
  public function checkoutCompletionMessage() {
    $text = 'Thank you for purchasing the billing budget! REMOVE ME?.';
    return $text;
  }
}

